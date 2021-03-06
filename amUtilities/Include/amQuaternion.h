/******************************************************************************
**
* @file    amQuaternion.h
* @author  Andr�s Sumano (andressumano@hotmail.com)
* @date    2018/6/28
* @brief   Implements a Quaternion.
*
* Implements a Quaternion.
*
* @bug     No known bugs.
*
******************************************************************************/
#pragma once
/***********************
**
*  Includes
*
***********************/
#include "amPrerequisitesUtilities.h"
#include "amVector3.h"

namespace amEngineSDK {
  class amQuaternion
  {
  public:
    amQuaternion();
    ~amQuaternion();

    /***********************
    *  @brief Copy constructor from another quaternion
    ***********************/
    amQuaternion
    (const amQuaternion& quat);;

    /***********************
    *  @brief Operator* returns conatenated quats and thier rotations
    ***********************/
    amQuaternion 
    operator*(const amQuaternion& other);

    /***********************
    *  @brief Ope *= does Ope* to this quat
    ***********************/
    amQuaternion&
    operator*=(const amQuaternion& other);

    /***********************
    *  @brief Constructor from vector and w value
    ***********************/
    amQuaternion
    (const amVector3& vec, const float _w);

   
    /***********************
    *  @brief Returns a quat with all its components multiplied by f
    ***********************/
    amQuaternion 
    operator *(const float & f);

    /***********************
    *  @brief Returns the dot product of this quat projected onto the given quat
    ***********************/
    float 
    quatDot(const amQuaternion& projectedOn);

    /***********************
    *  @brief Interpolates two quat rotations by f
    ***********************/
    amQuaternion 
    sLerp(amQuaternion& other, float& t);

    /***********************
    *  @brief Exponetializes this quat by the given value of exp
    ***********************/
    amQuaternion&
    quatPow(float& exp);

    /***********************
    *  @brief Initializes the quaternion on 0s
    ***********************/
    void init();

    /***********************
    *  @brief Initializes the quaternion as identity
    ***********************/
    void initIdentity();

    /***********************
    *  @brief Rotates the quaternion around the X axis
    ***********************/
    void rotateAroundX(const float& theta);

    /***********************
    *  @brief Rotates the quaternion around the Y axis
    ***********************/
    void rotateAroundY(const float& theta);

    /***********************
    *  @brief Rotates the quaternion around the Z axis
    ***********************/
    void rotateAroundZ(const float& theta);

    /***********************
    *  @brief Rotates the quaternion around the Given axis
    ***********************/
    void rotateAroundAxis(const amVector3 &axis, const float& theta);

    float w;
    amVector3 m_vec;
  };
}


