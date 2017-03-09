/*This contains the transformations of the body parts*/

#include "BodyHandler.h"

ref_ptr<Group> BodyHandler::getBody()
    {

    ref_ptr<MatrixTransform> torsoTransform = new MatrixTransform();
    torso = new Torso(torsoTransform.get());

    ref_ptr<MatrixTransform> HeadTransform = new MatrixTransform();
    HeadTransform->setMatrix(Matrix::translate(0.0f, 0.0f, 1.8f));
    head = new Head(HeadTransform.get());

    ref_ptr<MatrixTransform> rightHandTopTransform = new MatrixTransform();
    rightHandTopTransform->setMatrix(Matrix::translate(1.7f, 0.0f, 1.0f));
    rightHandTop = new RightHandTop(rightHandTopTransform.get());

    ref_ptr<MatrixTransform> leftHandTopTransform = new MatrixTransform();
    leftHandTopTransform->setMatrix(Matrix::translate(-1.7f, 0.0f, 1.0f));
    leftHandTop = new LeftHandTop(leftHandTopTransform.get());

    ref_ptr<MatrixTransform> rightLegTopTransform = new MatrixTransform();
    rightLegTopTransform->setMatrix(Matrix::translate(0.7f, 0.0f, -2.5f));
    rightLegTop = new RightLegTop(rightLegTopTransform.get());

    ref_ptr<MatrixTransform> leftLegTopTransform = new MatrixTransform();
    leftLegTopTransform->setMatrix(Matrix::translate(-0.7f, 0.0f, -2.5f));
    leftLegTop = new LeftLegTop(leftLegTopTransform.get());

    ref_ptr<MatrixTransform> rightHandBottomTransform = new MatrixTransform();
    rightHandBottomTransform->setMatrix(Matrix::translate(0.0f, 0.0f, -2.0f));
    rightHandBottom = new RightHandBottom(rightHandBottomTransform.get());

    ref_ptr<MatrixTransform> leftHandBottomTransform = new MatrixTransform();
    leftHandBottomTransform->setMatrix(Matrix::translate(0.0f, 0.0f, -2.0f));
    leftHandBottom = new LeftHandBottom(leftHandBottomTransform.get());

    ref_ptr<MatrixTransform> leftLegBottomTransform = new MatrixTransform();
    leftLegBottomTransform->setMatrix(Matrix::translate(0.0f, 0.0f, -2.0f));
    leftLegBottom = new LeftLegBottom(leftLegBottomTransform.get());

    ref_ptr<MatrixTransform> rightLegBottomTransform = new MatrixTransform();
    rightLegBottomTransform->setMatrix(Matrix::translate(0.0f, 0.0f, -2.0f));
    rightLegBottom = new RightLegBottom(rightLegBottomTransform.get());

    ref_ptr<MatrixTransform> rightFootTransform = new MatrixTransform();
    rightFootTransform->setMatrix(Matrix::translate(0.0f, 0.0f, -2.1f));
    rightFoot = new Feet(rightFootTransform.get());

    ref_ptr<MatrixTransform> leftFootTransform = new MatrixTransform();
    leftFootTransform->setMatrix(Matrix::translate(0.0f, 0.0f, -2.1f));
    leftFoot = new Feet(leftFootTransform.get());

    rightLegTop->addChildBodyPart(rightLegBottom->getTransform());
    leftLegTop->addChildBodyPart(leftLegBottom->getTransform());

    rightLegBottom->addChildBodyPart(rightFoot->getTransform());
    leftLegBottom->addChildBodyPart(leftFoot->getTransform());

    rightHandTop->addChildBodyPart(rightHandBottom->getTransform());
    leftHandTop->addChildBodyPart(leftHandBottom->getTransform());

    torso->addChildBodyPart(head->getTransform());
    torso->addChildBodyPart(rightHandTop->getTransform());
    torso->addChildBodyPart(leftHandTop->getTransform());
    torso->addChildBodyPart(leftLegTop->getTransform());
    torso->addChildBodyPart(rightLegTop->getTransform());
    
    ref_ptr<Group> body = new Group();
    body->addChild(torso->getTransform());

    return body;
    }
