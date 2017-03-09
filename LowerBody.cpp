
/* The C++ File which has the classes and methods to Implement
* Thigh of the left leg
* Below Thigh of the left leg
* Thigh of the right leg
* Below Thigh of the right leg
* The two feet
*/

#pragma once
#include "LowerBody.h"

// The top part of the left leg
LeftLegTop::LeftLegTop(ref_ptr<MatrixTransform> transform) : BodyCredential(transform)
    {
    shape->setShape(new Capsule(Vec3(0.0f, 0.0f, -0.8f), 0.5f, 1.8f));
    rotationAngleX = rotationAngleY = rotationAngleZ = 0.0f;
    rotationVectorX = Vec3(-1.0f, 0.0f, 0.0f);
    rotationVectorY = Vec3(0.0f, 1.0f, 0.0f);
    rotationVectorZ = Vec3(0.0f, 0.0f, -1.0f);
    isShiftKeyPressed = false;
    }

bool LeftLegTop::handle(const GUIEventAdapter & eventAdapter, GUIActionAdapter & actionAdapter)
    {

    Matrix matX, matY, matZ;
    switch ( eventAdapter.getEventType() )
	{

    case osgGA::GUIEventAdapter::KEYDOWN:
	switch ( eventAdapter.getKey() )
	    {

	case GUIEventAdapter::KEY_Shift_L:case GUIEventAdapter::KEY_Shift_R:
	    isShiftKeyPressed = true;
	    break;

	case GUIEventAdapter::KEY_Left:
	    if(isSelected && !isShiftKeyPressed)
		{
		if(rotationAngleY < DegreesToRadians(45.0)){
		    rotationAngleY += PI/180;
		    matY = Matrix::rotate(PI/180, rotationVectorY);
		    transform->setMatrix(matY*transform->getMatrix());
		    }
		}

	    if(isSelected && isShiftKeyPressed)
		{
		if(rotationAngleZ < DegreesToRadians(10.0f)){
		    rotationAngleZ += PI/180;
		    matZ = Matrix::rotate(PI/180, rotationVectorZ);
		    transform->setMatrix(matZ*transform->getMatrix());
		    }
		}

	    break;

	case GUIEventAdapter::KEY_Right:
	    if(isSelected && !isShiftKeyPressed)
		{
		if(rotationAngleY > DegreesToRadians(0.0f)){
		    rotationAngleY -= PI/180;
		    matY = Matrix::rotate(-PI/180, rotationVectorY);
		    transform->setMatrix(matY*transform->getMatrix());
		    }
		}

	    if(isSelected && isShiftKeyPressed)
		{
		if(rotationAngleZ > DegreesToRadians(0.0f)){
		    rotationAngleZ -= PI/180;
		    matZ = Matrix::rotate(-PI/180, rotationVectorZ);
		    transform->setMatrix(matZ*transform->getMatrix());
		    }
		}
	    break;
	case GUIEventAdapter::KEY_Up:
	    if(isSelected)
		{
		if(rotationAngleX < DegreesToRadians(90.0))
		    {
		    rotationAngleX += PI/180;
		    matX = Matrix::rotate(PI/180, rotationVectorX);
		    transform->setMatrix(matX*transform->getMatrix());
		    }
		}
	    break;

	case GUIEventAdapter::KEY_Down:
	    if(isSelected)
		{
		if(rotationAngleX > DegreesToRadians(0.0f))
		    {
		    rotationAngleX -= PI/180;
		    matX = Matrix::rotate(-PI/180, rotationVectorX);
		    transform->setMatrix(matX*transform->getMatrix());
		    }
		}
	    break;

	case '6':
	    shape->setColor(Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	    isSelected = true;
	    break;
	case '1': case '2': case '3': case '4':
	case '5': case '9': case '7': case '8':
	case '0': 
	    shape->setColor(Vec4(0.0f, 0.0f, 1.0f, 1.0f));
	    isSelected = false;
	    break;

	    }
	break;
    case GUIEventAdapter::KEYUP:
	if(eventAdapter.getKey() == GUIEventAdapter::KEY_Shift_L || eventAdapter.getKey() == GUIEventAdapter::KEY_Shift_R)
	    isShiftKeyPressed = false;
	break;
	}
    return false;
    }

LeftLegTop::~LeftLegTop(void)
    {
    }

// The top of the right leg
RightLegTop::RightLegTop(ref_ptr<MatrixTransform> transform) : BodyCredential(transform)
    {
    shape->setShape(new Capsule(Vec3(0.0f, 0.0f, -0.8f), 0.5f, 1.8f));
    rotationAngleX = rotationAngleY = rotationAngleZ = 0.0f;
    rotationVectorX = Vec3(-1.0f, 0.0f, 0.0f);
    rotationVectorY = Vec3(0.0f, -1.0f, 0.0f);
    rotationVectorZ = Vec3(0.0f, 0.0f, 1.0f);
    isShiftKeyPressed = false;
    }

bool RightLegTop::handle(const GUIEventAdapter & eventAdapter, GUIActionAdapter & actionAdapter)
    {
    Matrix matX, matY, matZ;

    switch ( eventAdapter.getEventType() )
	{

    case osgGA::GUIEventAdapter::KEYDOWN:
	switch ( eventAdapter.getKey() )
	    {

	case GUIEventAdapter::KEY_Shift_L:case GUIEventAdapter::KEY_Shift_R:
	    isShiftKeyPressed = true;
	    break;

	case GUIEventAdapter::KEY_Right:
	    if(isSelected && !isShiftKeyPressed)
		{
		if(rotationAngleY < DegreesToRadians(45.0)){
		    rotationAngleY += PI/180;
		    matY = Matrix::rotate(PI/180, rotationVectorY);
		    transform->setMatrix(matY*transform->getMatrix());
		    }
		}
	    if(isSelected && isShiftKeyPressed)
		{
		if(rotationAngleZ < DegreesToRadians(10.0))
		    {
		    rotationAngleZ += PI/180;
		    matZ = Matrix::rotate(PI/180, rotationVectorZ);
		    transform->setMatrix(matZ*transform->getMatrix());
		    }
		}
	    break;

	case GUIEventAdapter::KEY_Left:
	    if(isSelected && !isShiftKeyPressed)
		{
		if(rotationAngleY > DegreesToRadians(0.0f)){
		    rotationAngleY -= PI/180;
		    matY = Matrix::rotate(-PI/180, rotationVectorY);
		    transform->setMatrix(matY*transform->getMatrix());
		    }
		}
	    if(isSelected && isShiftKeyPressed)
		{
		if(rotationAngleZ > DegreesToRadians(0.0f)){
		    rotationAngleZ -= PI/180;
		    matZ = Matrix::rotate(-PI/180, rotationVectorZ);
		    transform->setMatrix(matZ*transform->getMatrix());
		    }
		}
	    break;

	case GUIEventAdapter::KEY_Up:
	    if(isSelected)
		{
		if(rotationAngleX < DegreesToRadians(90.0))
		    {
		    rotationAngleX += PI/180;
		    matX = Matrix::rotate(PI/180, rotationVectorX);
		    transform->setMatrix(matX*transform->getMatrix());
		    }
		}
	    break;

	case GUIEventAdapter::KEY_Down:
	    if(isSelected)
		{
		if(rotationAngleX > DegreesToRadians(0.0f))
		    {
		    rotationAngleX -= PI/180;
		    matX = Matrix::rotate(-PI/180, rotationVectorX);
		    transform->setMatrix(matX*transform->getMatrix());
		    }
		}
	    break;
	case '7':
	    shape->setColor(Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	    isSelected = true;
	    break;
	case '1': case '2': case '3': case '4':
	case '5': case '6': case '9': case '8':
	case '0': 
	    shape->setColor(Vec4(0.0f, 0.0f, 1.0f, 1.0f));
	    isSelected = false;
	    break;

	    }
	break;
    case GUIEventAdapter::KEYUP:
	if(eventAdapter.getKey() == GUIEventAdapter::KEY_Shift_L || eventAdapter.getKey() == GUIEventAdapter::KEY_Shift_R)
	    isShiftKeyPressed = false;
	break;
	}
    return false;
    }

RightLegTop::~RightLegTop(void)
    {

    }

//Bottom of the right leg
RightLegBottom::RightLegBottom(ref_ptr<MatrixTransform> transform) : BodyCredential(transform)
    {
    shape->setShape(new Cylinder(Vec3(0.0f, 0.0f, -1.0f), 0.40f, 2.0f));
    rotationAngle = 0.0f;
    rotationVector = Vec3(1.0f, 0.0f, 0.0f);
    }

bool RightLegBottom::handle(const GUIEventAdapter & eventAdapter, GUIActionAdapter & actionAdapter)
    {
    Matrix m;

    switch ( eventAdapter.getEventType() )
	{

    case osgGA::GUIEventAdapter::KEYDOWN:
	switch ( eventAdapter.getKey() )
	    {
	case GUIEventAdapter::KEY_Up:
	    if(isSelected)
		{
		if(rotationAngle < DegreesToRadians(80.0))
		    {
		    rotationAngle += PI/180;
		    m = Matrix::rotate(PI/180, rotationVector);
		    transform->setMatrix(m*transform->getMatrix());
		    }
		}
	    break;

	case GUIEventAdapter::KEY_Down:
	    if(isSelected)
		{
		if(rotationAngle > DegreesToRadians(0.0f))
		    {
		    rotationAngle -= PI/180;
		    m = Matrix::rotate(-PI/180, rotationVector);
		    transform->setMatrix(m*transform->getMatrix());
		    }
		}
	    break;

	case '9':
	    shape->setColor(Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	    isSelected = true;
	    break;
	case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8':
	case '0': 
	    shape->setColor(Vec4(0.0f, 0.0f, 1.0f, 1.0f));
	    isSelected = false;
	    break;

	    }
	}
    return false;
    }

RightLegBottom::~RightLegBottom(void)
    {
    }

//Bottom of the left leg
LeftLegBottom::LeftLegBottom(ref_ptr<MatrixTransform> transform) : BodyCredential(transform)
    {
    shape->setShape(new Cylinder(Vec3(0.0f, 0.0f, -1.0f), 0.40f, 2.0f));
    rotationAngle = 0.0f;
    rotationVector = Vec3(1.0f, 0.0f, 0.0f);
    }

bool LeftLegBottom::handle(const GUIEventAdapter & eventAdapter, GUIActionAdapter & actionAdapter)
    {
    Matrix m;
    switch ( eventAdapter.getEventType() )
	{

    case osgGA::GUIEventAdapter::KEYDOWN:
	switch ( eventAdapter.getKey() )
	    {
	case GUIEventAdapter::KEY_Up:
	    if(isSelected)
		{
		if(rotationAngle < DegreesToRadians(80.0))
		    {
		    rotationAngle += PI/180;
		    m = Matrix::rotate(PI/180, rotationVector);
		    transform->setMatrix(m*transform->getMatrix());
		    }
		}
	    break;

	case GUIEventAdapter::KEY_Down:
	    if(isSelected)
		{
		if(rotationAngle > DegreesToRadians(0.0f))
		    {
		    rotationAngle -= PI/180;
		    m = Matrix::rotate(-PI/180, rotationVector);
		    transform->setMatrix(m*transform->getMatrix());
		    }
		}
	    break;

	case '8':
	    shape->setColor(Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	    isSelected = true;
	    break;
	case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '9':
	case '0': 
	    shape->setColor(Vec4(0.0f, 0.0f, 1.0f, 1.0f));
	    isSelected = false;
	    break;

	    }
	}
    return false;
    }

LeftLegBottom::~LeftLegBottom(void)
    {
    }


//Feet
Feet::Feet(ref_ptr<MatrixTransform> transform) : BodyCredential(transform)
    {
    shape->setShape(new Box(Vec3(0.0f, -0.22f, -0.05f), 0.8f, 1.2f, 0.3f));
    }

bool Feet::handle( const GUIEventAdapter & eventAdapter, GUIActionAdapter & actionAdapter )
    {
    return false;
    }

Feet::~Feet(void)
    {
    }
