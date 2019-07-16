#pragma once
#include "amDXPreReqs.h"
#include <amInputLayout.h>
#include "amDXDevice.h"

namespace amEngineSDK {
  class amDXDeviceContext;
  class amVertexShader;

  class amDXInputLayout : public amInputLayout
  {
  public:
    amDXInputLayout();
    ~amDXInputLayout();
    
    int32
    Create(amDXDevice* _pDV, amVertexShader* _pShaderBlob);
    
    void
    setLayout(amDXDeviceContext* pDC);
    //uint32 numElements = sizeof(layout) / sizeof(layout[0]);

    ID3D11InputLayout* m_pVertexLayout;
    Vector<D3D11_INPUT_ELEMENT_DESC> m_layout =
    {
      {"POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0},
      {"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0},
      {"NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 28, D3D11_INPUT_PER_VERTEX_DATA, 0},
      {"TANGENT",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 40, D3D11_INPUT_PER_VERTEX_DATA, 0},
      {"BINORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 52, D3D11_INPUT_PER_VERTEX_DATA, 0}
    };
  };
}
