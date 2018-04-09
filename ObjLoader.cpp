// 2017-18 Samuel Mounter
// All rights reserved

#include "ObjLoader.h"

ObjLoader::ObjLoader()
{
}

ObjLoader::ObjLoader(char * filename)
{
	loadObj(filename);
}

ObjLoader::~ObjLoader()
{
	//delete polygons
	int numPolyEnd = polygons.size();
	for (int j = 0; j < numPolyEnd; j++)
	{
		delete polygons[j];
		polygons[j] = NULL;
	}

	polygons.erase(polygons.begin(), polygons.end());

	//delete vertices
	int numVertEnd = vertices.size();
	for (int j = 0; j < numVertEnd; j++)
	{
		delete vertices[j];
		vertices[j] = NULL;
	}

	vertices.erase(vertices.begin(), vertices.end());

	//delete normals
	int numNormEnd = normals.size();
	for (int j = 0; j < numNormEnd; j++)
	{
		delete normals[j];
		normals[j] = NULL;
	}

	normals.erase(normals.begin(), normals.end());
}

int ObjLoader::loadObj(char * filename)
{
	numVert = 0;
	numPoly = 0;
	numNorm = 0;
	scaleValue = 100;
	strcpy(name, filename);

	FILE *file;
	char charVariable, line[256];
	if ((file = fopen(name, "rt")) == NULL) //if no such file exists
	{
		printf("File not found\n");
		return 1; //error
	}

	float v1, v2, v3;
	while (!feof(file))
	{
		fscanf(file, "%c", &charVariable);
		if (charVariable == '\n') fscanf(file, "%c", &charVariable); //move to the next line

		if (charVariable == 'v') //vertex
		{
			fscanf(file, "%c", &charVariable);

			if (charVariable == ' ') //standard vertex
			{
				fscanf(file, "%f %f %f", &v1, &v2, &v3);
				Point3D* vert = new Point3D(v1, v2, v3);
				vertices.push_back(vert);
				numVert++;
			}
			else if (charVariable == 'n') //normal
			{
				fscanf(file, "%f %f %f", &v1, &v2, &v3);
				Normal* norm = new Normal(v1, v2, v3);
				normals.push_back(norm);
				numNorm++;
			}
		}
		else if (charVariable == 'f') //face
		{
			int p1, p2, p3, n1, n2, n3;

			//assuming a structure like this - f 1//1 2//2 3//3
			fscanf(file, "%c", &charVariable); //read space char - ignore this
			fscanf(file, "%d", &p1); //read vertex.
			fscanf(file, "%c", &charVariable); //read space char - ignore this
			fscanf(file, "%c", &charVariable); //read space char - ignore this
			fscanf(file, "%d", &n1); //read normal.

			fscanf(file, "%c", &charVariable); //read space char - ignore this
			fscanf(file, "%d", &p2); //read vertex.
			fscanf(file, "%c", &charVariable); //read space char - ignore this
			fscanf(file, "%c", &charVariable); //read space char - ignore this
			fscanf(file, "%d", &n2); //read normal.

			fscanf(file, "%c", &charVariable); //read space char - ignore this
			fscanf(file, "%d", &p3); //read vertex.
			fscanf(file, "%c", &charVariable); //read space char - ignore this
			fscanf(file, "%c", &charVariable); //read space char - ignore this
			fscanf(file, "%d", &n3); //read normal.
			
			Polygon* poly = new Polygon(
				Point3D(vertices[p1 - 1]->x * scaleValue, vertices[p1 - 1]->y * scaleValue, vertices[p1 - 1]->z * scaleValue),
				Point3D(vertices[p2 - 1]->x * scaleValue, vertices[p2 - 1]->y * scaleValue, vertices[p2 - 1]->z * scaleValue),
				Point3D(vertices[p3 - 1]->x * scaleValue, vertices[p3 - 1]->y * scaleValue, vertices[p3 - 1]->z * scaleValue),
				Normal(normals[n1 - 1]->x, normals[n1 - 1]->y, normals[n1 - 1]->z), 
				Normal(normals[n2 - 1]->x, normals[n2 - 1]->y, normals[n2 - 1]->z),
				Normal(normals[n3 - 1]->x, normals[n3 - 1]->y, normals[n3 - 1]->z)
			);
			polygons.push_back(poly);
			numPoly++;
		}
		else //comment line
		{
			fgets(line, 256, file);
		}
	}

	fclose(file);
	return 0; //no error
}

int ObjLoader::printInfo()
{
	int i;

	printf("VERTICES: %d\n", numVert);
	for (i = 0; i < numVert; i++)
	{
		printf("%f %f %f\n", vertices[i]->x, vertices[i]->y, vertices[i]->z);
	}

	printf("NORMALS: %d\n", numNorm);
	for (i = 0; i < numNorm; i++)
	{
		printf("%f %f %f\n", normals[i]->x, normals[i]->y, normals[i]->z);
	}

	printf("POLYGONS: %d\n", numPoly);
	for (i = 0; i < numPoly; i++) //for each vertex of polygon (triangle)
	{
		printf("Number - %d\n", i + 1);
	}

	return 0;
}
