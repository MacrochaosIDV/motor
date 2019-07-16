#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amGameObject;
  class amCamera;
  class amResource;

  namespace amNodeType {
    enum E
    {
      kROOT = 0,
      kNORMAL,
      kRESOURCE,
      kEMPTY,
      kCOUNT
    };
  }

  class AM_CORE_EXPORT amSceneNode
  {
  public:
    amSceneNode(amSceneNode* _parent,
                amNodeType::E _type = amNodeType::E::kNORMAL,
                bool _isVisible = false);
    amSceneNode(amSceneNode* _parent,
                amGameObject* _obj,
                amNodeType::E _type = amNodeType::E::kNORMAL,
                bool _isVisible = true);
    ~amSceneNode();

    Vector<amSceneNode*>&
    getAllChildrenInCam(amCamera* _cam);

    Vector<amResource*>&
    getAllResourcesInCam(amCamera* _cam);

    Vector<amSceneNode*>& 
    getAllChildren();

    void 
    addChildren(const Vector<amSceneNode*>& _children);

    void 
    setParent(amSceneNode* _parent);

    void 
    addChild(amSceneNode* _child);

    void
    addChild(amGameObject* _childObj);

    void 
    addEmpty();

    void
    removeChild(amSceneNode* _child);

    void 
    setNodeAsRoot(amSceneNode* _root);

    void 
    setGameObj(amGameObject* _obj);

    bool 
    camOverlap(amCamera* _cam);

    bool m_isVisible;
    amNodeType::E m_type;
    amSceneNode* m_parent;
    Vector<amSceneNode*> m_vecChildren;
    amGameObject* m_nodeObj;
  };
}
