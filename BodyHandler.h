/* Transformations*/

#include "BodyCredential.h"
#include "UpperBody.h"
#include "LowerBody.h"

class BodyHandler 
{

    private:
    ref_ptr<Torso> torso;
    ref_ptr<Head> head;
    ref_ptr<RightHandTop> rightHandTop;
    ref_ptr<LeftHandTop> leftHandTop;
    ref_ptr<RightLegTop> rightLegTop;
    ref_ptr<LeftLegTop> leftLegTop;
    ref_ptr<LeftHandBottom> leftHandBottom;
    ref_ptr<RightHandBottom> rightHandBottom;
    ref_ptr<LeftLegBottom> leftLegBottom;
    ref_ptr<RightLegBottom> rightLegBottom;
    ref_ptr<Feet> rightFoot;
    ref_ptr<Feet> leftFoot;

    public:
    ref_ptr<Group> getBody();
    ref_ptr<Torso> getTorso(){return torso;}
    ref_ptr<Head> getHead(){return head;}
    ref_ptr<LeftHandTop> getLeftHandTop(){return leftHandTop;}
    ref_ptr<RightHandTop> getRightHandTop(){return rightHandTop;}
    ref_ptr<LeftHandBottom> getLeftHandBottom(){return leftHandBottom;}
    ref_ptr<RightHandBottom> getRightHandBottom(){return rightHandBottom;}
    ref_ptr<LeftLegTop> getLeftLegTop(){return leftLegTop;}
    ref_ptr<RightLegTop> getRightLegTop(){return rightLegTop;}
    ref_ptr<LeftLegBottom> getLeftLegBottom(){return leftLegBottom;}
    ref_ptr<RightLegBottom> getRightLegBottom(){return rightLegBottom;}
};