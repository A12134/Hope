/*Discarded class, the LOD functionality has been intergraded with the model class*/

/*
#include "LODmesh.h"



LODmesh::LODmesh(mesh * lvl1, mesh * lvl2, mesh * lvl3, mesh * lvl4, mesh * lvl5)
{
	this->lvl_1_mesh = lvl1;
	this->lvl_2_mesh = lvl2;
	this->lvl_3_mesh = lvl3;
	this->lvl_4_mesh = lvl4;
	this->lvl_5_mesh = lvl5;
	currentLvl = LODLvl::lvl_1;
}

LODmesh::LODmesh(mesh * lvl1, mesh * lvl2, mesh * lvl3, mesh * lvl4)
{
	this->lvl_1_mesh = lvl1;
	this->lvl_2_mesh = lvl2;
	this->lvl_3_mesh = lvl3;
	this->lvl_4_mesh = lvl4;
	this->lvl_5_mesh = lvl4;
	currentLvl = LODLvl::lvl_1;
}

LODmesh::LODmesh(mesh * lvl1, mesh * lvl2, mesh * lvl3)
{
	this->lvl_1_mesh = lvl1;
	this->lvl_2_mesh = lvl2;
	this->lvl_3_mesh = lvl3;
	this->lvl_4_mesh = lvl3;
	this->lvl_5_mesh = lvl3;
	currentLvl = LODLvl::lvl_1;
}

LODmesh::LODmesh(mesh * lvl1, mesh * lvl2)
{
	this->lvl_1_mesh = lvl1;
	this->lvl_2_mesh = lvl2;
	this->lvl_3_mesh = lvl2;
	this->lvl_4_mesh = lvl2;
	this->lvl_5_mesh = lvl2;
	currentLvl = LODLvl::lvl_1;
}

LODmesh::LODmesh(mesh * lvl1)
{
	this->lvl_1_mesh = lvl1;
	this->lvl_2_mesh = lvl1;
	this->lvl_3_mesh = lvl1;
	this->lvl_4_mesh = lvl1;
	this->lvl_5_mesh = lvl1;
	currentLvl = LODLvl::lvl_1;
}

LODmesh::~LODmesh()
{
}

void LODmesh::render(shaderProgram* shaderSP, mat4 projection, mat4 view, mat4 model)
{
	switch (currentLvl)
	{
	case LODLvl::lvl_1:
		this->lvl_1_mesh->render(shaderSP, projection, model, view);
		break;
	case LODLvl::lvl_2:
		this->lvl_2_mesh->render(shaderSP, projection, model, view);
		break;
	case LODLvl::lvl_3:
		this->lvl_3_mesh->render(shaderSP, projection, model, view);
		break;
	case LODLvl::lvl_4:
		this->lvl_4_mesh->render(shaderSP, projection, model, view);
		break;
	case LODLvl::lvl_5:
		this->lvl_5_mesh->render(shaderSP, projection, model, view);
		break;
	default:
		break;
	}
}
*/