#include "OBJLoader.h"





namespace OBJLoader
{
	void LoadVertex(vector<Vertex>& vertices, string& line)
	{
		stringstream strstm;
		string tempString;

		Vertex v;

		strstm << line;

		strstm>>tempString;
		strstm >> v.x;
		strstm >> v.y;
		strstm >> v.z;

		vertices.push_back(v);
	}

	void LoadTexCoord(vector<TexCoord>& texCoords, string& line)
	{
		stringstream strstm;
		string tempString;

		float tempFloat;
		TexCoord v;

		strstm << line;

		strstm>>tempString;
		strstm >> v.u;
		strstm >> v.v;
		strstm >> tempFloat;


		texCoords.push_back(v);
	}

	void LoadNormal(vector<Vector3>& normals, string& line)
	{
		stringstream strstm;
		string tempString;

		Vector3 v;

		strstm << line;

		strstm>>tempString;
		strstm >> v.x;
		strstm >> v.y;
		strstm >> v.z;

		normals.push_back(v);

	}

	void LoadIndex(vector<GLushort>& indices, string& line)
	{
		stringstream strstm;
		string tempString;

		string faces[3];

		strstm.str("");
		strstm.clear();
		strstm << line;

		strstm>>tempString;

		strstm >> faces[0];
		strstm >> faces[1];
		strstm >> faces[2];

		for (int i = 0; i < 3; i++)
		{
			strstm.str("");
			strstm.clear();
			strstm << faces[i];
			getline(strstm,line,'/');
			indices.push_back(stoi(line) - 1);
			getline(strstm,line,'/');
			indices.push_back(stoi(line) - 1);
			getline(strstm,line,'/');
			indices.push_back(stoi(line) - 1);
		}
		
	}

	void ConvertToMesh(OBJMesh& mesh, vector<Vertex>& vertices, vector<Vector3>& normals, vector<TexCoord>& texCoords, vector<vector<GLushort>>& indices)
	{
		int indexcount = 0;

		for (int i = 0; i <indices.size(); i++)
		{
			vector<GLushort> currentIndices;
			for (int j = 0; j < indices[i].size(); j=j+3)
			{
				currentIndices.push_back(indexcount);

				mesh.Vertices.push_back(vertices[indices[i][j]]);
				mesh.TexCoords.push_back(texCoords[indices[i][j+1]]);
				mesh.Normals.push_back(normals[indices[i][j+2]]);

				indexcount++;
			}
			mesh.MeshIndices.push_back(currentIndices);
		}
	}

	OBJMesh* OBJLoader::LoadOBJ(char* path)
	{

		vector<Vertex> vertices;
		vector<Vector3> normals;
		vector<TexCoord> texCoords;
		vector<vector<GLushort>> currentIndices;
		vector<GLushort> indices;

		string line;
		stringstream strstm;
		string tempString;

		OBJMesh* mesh = new OBJMesh();

		ifstream inFile;

		inFile.open(path);

		if(!inFile.good())
		{
			cerr << "Can't open texture file " << path << endl;
			return nullptr;
		}

		while (!inFile.eof())
		{
			getline(inFile, line);

			if (line.length() > 2)
			{
				switch (line.at(0))
				{
				case 'v':
					switch (line.at(1))					
					{
					case ' ':
						LoadVertex(vertices, line);
						break;
					case 'n':
						LoadNormal(normals, line);
						break;
					case 't':
						LoadTexCoord(texCoords, line);
						break;
					}
					break;
				case 'f':
					LoadIndex(currentIndices.back(), line);
					break;
				case '#':
					strstm.str("");
					strstm.clear();
					strstm << line;

					strstm >> tempString;
					strstm >> tempString;

					if (tempString == "object")
					{
						strstm >> tempString;

						mesh->MeshNames.push_back(tempString);

						vector<GLushort> indices;
						currentIndices.push_back(indices);
					}
					break;
				}
			}
		}
	int test = 0;
		ConvertToMesh(*mesh, vertices, normals, texCoords, currentIndices);
		return mesh;
	}
}
//	int LoadTextureTGA(const char* textureFileName)
//	{
//		int ID;
//		char* tempHeaderData = new char[18]; //18 Bytes is TGA Header Size
//		char* tempTextureData;  
//		int fileSize;
//		char type, pixelDepth, mode;
//
//		ifstream inFile;
//
//		inFile.open(textureFileName, ios::binary);
//		if (!inFile.good())  
//		{
//			cerr  << "Can't open texture file " << textureFileName << endl;
//			return -1;
//		}
//
//		//18 Bytes is the size of a TGA Header
//		inFile.seekg (0, ios::beg); //Seek back to beginning of file
//		inFile.read (tempHeaderData, 18); //Read in all the data in one go
//
//		inFile.seekg (0, ios::end); //Seek to end of file
//		fileSize = (int)inFile.tellg() - 18; //Get current position in file - The End, this gives us total file size
//		tempTextureData = new char [fileSize]; //Create an new aray to store data
//		inFile.seekg (18, ios::beg); //Seek back to beginning of file + 18
//		inFile.read (tempTextureData, fileSize); //Read in all the data in one go
//		inFile.close(); //Close the file
//
//		type = tempHeaderData[2]; //Get TGA Type out of Header - Must be RGB for this to work
//		int _width = ((unsigned char)tempHeaderData[13] << 8u) + (unsigned char)tempHeaderData[12]; // Find the width (Combines two bytes into a short)
//		int _height = ((unsigned char)tempHeaderData[15] << 8u) + (unsigned char)tempHeaderData[14]; //Find the height
//		pixelDepth = tempHeaderData[16]; // Find the pixel depth (24/32bpp)
//
//		bool flipped = false;
//		if ((int)((tempHeaderData[11] << 8) + tempHeaderData[10]) == 0)
//			flipped = true;
//
//		//We only support RGB type
//		if (type == 2)
//		{
//			cout << textureFileName << " loaded." << endl;
//
//			glGenTextures(1, ID); //Get next Texture ID
//			glBindTexture(GL_TEXTURE_2D, *ID); //Bind the texture to the ID
//
//			mode = pixelDepth / 8;
//
//			//Note that TGA files are stored as BGR(A) - So we need to specify the format as GL_BGR(A)_EXT
//			if (mode == 4)
//				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, tempTextureData);
//			else
//				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, tempTextureData);
//		}		
//	}
//
//	delete [] tempHeaderData; //We don't need the header memory anymore
//	delete [] tempTextureData; //Clear up the data - We don't need this any more
//
//	return ID;
//}
