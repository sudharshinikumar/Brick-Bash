/* The header File which has the classes and methods to Implement
* Thigh of the left leg
* Below Thigh of the left leg
* Thigh of the right leg
* Below Thigh of the right leg
* The two feet
*/

#pragma once
#include "BodyCredential.h"
class LeftLegTop :
    public BodyCredential
    {
    public:
	LeftLegTop(ref_ptr<MatrixTransform> transform);
	virtual bool handle(const GUIEventAdapter & eventAdapter, GUIActionAdapter & actionAdapter);
	~LeftLegTop(void);

    private:
	float rotationAngleX, rotationAngleY, rotationAngleZ;
	Vec3 rotationVectorX, rotationVectorY, rotationVectorZ;
	bool isShiftKeyPressed;
    };
class LeftLegBottom :
    public BodyCredential
    {
    public:
	LeftLegBottom(ref_ptr<MatrixTransform> transform);
	virtual bool handle( const GUIEventAdapter & eventAdapter, GUIActionAdapter & actionAdapter );
	~LeftLegBottom(void);

    private:
	float rotationAngle;
	Vec3 rotationVector;
    };

class RightLegTop :
    public BodyCredential
    {
    public:
	RightLegTop(ref_ptr<MatrixTransform> transform);
	virtual bool handle(const GUIEventAdapter & eventAdapter, GUIActionAdapter & actionAdapter);
	~RightLegTop(void);

    private:
	float rotationAngleX, rotationAngleY, rotationAngleZ;
	Vec3 rotationVectorX, rotationVectorY, rotationVectorZ;
	bool isShiftKeyPressed;
    };

class RightLegBottom :
    public BodyCredential
    {
    public:
	RightLegBottom(ref_ptr<MatrixTransform> transform);
	virtual bool handle( const GUIEventAdapter & eventAdapter, GUIActionAdapter & actionAdapter );
	~RightLegBottom(void);

    private:
	float rotationAngle;
	Vec3 rotationVector;
    };

class Feet :
    public BodyCredential
    {
    public:
	Feet(ref_ptr<MatrixTransform> transform);
        virtual bool handle( const GUIEventAdapter & eventAdapter, GUIActionAdapter & actionAdapter );
	~Feet(void);
    };
