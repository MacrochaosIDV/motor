#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amPixelShader;
  class amVertexShader;
  class amModel;
  class amConstantBuffer;
  class amRenderTarget;
  class amResource;
  class amDeviceContext;

  namespace amRenderPassStage {
    enum E
    {
      kG_BUFFER = 0,
      kSSAO,
      kDOWNSCALE_BLOOM,
      kBLUR_H,
      kBLUR_V,
      kLUMINANCE,
      kFINAL,
      kCOUNT
    };
  }

  class AM_CORE_EXPORT amRenderPass
  {
  public:
    amRenderPass() = default;
    amRenderPass(const uint32 _pass, 
                 String _strPS, 
                 String _strVS, 
                 String _name);
    ~amRenderPass();

    void 
    render(Vector<amResource*>* _renderObjs);

    int32 
    compileShaders();

    virtual void
    setShaders(String _strPS, String _strVS);

    virtual void
    setShaderPointers(amVertexShader* _pVS, amPixelShader* _pPS);

    virtual void
    setRenderTargetsInputs(Vector<amRenderTarget*> _vecRenderTargets);

    virtual void 
    setUp(amDeviceContext* _dc);

    virtual void 
    addModels(Vector<amResource*>* _mdls);


    bool m_computeShading;
    String m_passName;
    String m_strPS;
    String m_strVS;
    amRenderPassStage::E m_renderPassStage;
    amVertexShader* m_pVS;
    amPixelShader* m_pPS;
    amConstantBuffer* m_vsConstBuffer;
    amConstantBuffer* m_psConstBuffer;
    Vector<amResource*> m_vecPassModels;
    Vector<amConstantBuffer*> m_vecPassConstBuffers;
    Vector<amRenderTarget*> m_vecRenderTargets;
    amRenderTarget* m_outRenderTarget;
    //
  };
}
