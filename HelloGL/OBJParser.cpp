#include "OBJParser.h"



OBJParser::OBJParser(void)
{
}


OBJParser::~OBJParser(void)
{
}
Mesh* OBJParser::Load(char* path)
{
	Mesh* mesh = new Mesh();

	ifstream inFile;

	inFile.open(path);

	if (!inFile.good())  
	{
		cerr  << "Can't open texture file " << path << endl;		
	}
	else
	{

		lineBuffer = new char[256];
		while (!inFile.eof())
		{

			inFile.getline(lineBuffer, 256);
			coordinates.push_back(new string(lineBuffer));


		}
		for(int i=0;i<coordinates.size();i++)
		{
			if(coordinates[i]->c_str()[0]=='#')
				continue;
			//VECTORS
			else if(coordinates[i]->c_str()[0]=='v' && coordinates[i]->c_str()[1]==' ')
			{
				float tempX,tempY,tempZ;
				sscanf(coordinates[i]->c_str(),"v %f %f %f",tempX,tempY,tempZ);
				vertexs.push_back(new Vector3(tempX,tempY,tempZ));
			}
			//NORMALS
			else if(coordinates[i]->c_str()[0]=='v' && coordinates[i]->c_str()[1]=='n')
			{
				float tempX,tempY,tempZ;
				sscanf(coordinates[i]->c_str(),"vn %f %f %f",tempX,tempY,tempZ);
				normals.push_back(new Vector3(tempX,tempY,tempZ));
			}
			//TEXTURE COORDS
			else if(coordinates[i]->c_str()[0]=='v' && coordinates[i]->c_str()[1]=='t')
			{
				float tempX,tempY,tempZ;
				sscanf(coordinates[i]->c_str(),"vt %f %f %f",tempX,tempY,tempZ);
				texcoords.push_back(new Vector3(tempX,tempY,tempZ));
			}
			//FACES
			else if(coordinates[i]->c_str()[0]=='f' && coordinates[i]->c_str()[1]==' ')
			{
				int tempX1,tempY1,tempZ1, tempX2, tempY2, tempZ2,  tempX3, tempY3, tempZ3;
				sscanf(coordinates[i]->c_str(),"f %f %f %f  %f %f %f  %f %f %f",tempX1,tempY1,tempZ1, tempX2,tempY2,tempZ2, tempX3,tempY3,tempZ3);
				Face * temp;
				temp->aV = tempX1;
				temp->aT = tempY1;
				temp->aN = tempZ1;
				temp->bV = tempX2;
				temp->bT = tempY2;
				temp->bN = tempZ2;
				temp->cV = tempX3;
				temp->cT = tempY3;
				temp->cN = tempZ3;
				faces.push_back(temp);
			}

			inFile.close();
			delete(lineBuffer);


			return mesh;
		}
	}
}
