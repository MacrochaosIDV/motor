#include "amDXDeviceContext.h"
#include "amDXVertexShader.h"
#include "amDXPixelShader.h"
#include "amDXComputeShader.h"
#include "amDXDepthStencilView.h"
#include "amDXRenderTargetView.h"
#include "amDXVertexBuffer.h"
#include "amDXIndexBuffer.h"
#include "amDXInputLayout.h"
#include <amVector4.h>


namespace amEngineSDK {
  amDXDeviceContext::amDXDeviceContext() {}

  amDXDeviceContext::~amDXDeviceContext() {}

  void amDXDeviceContext::setPrimitiveTopology(amPrimitiveTopology::E _pt) {
    m_pDC->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(_pt));
  }

  void amDXDeviceContext::setInputLayout(amInputLayout * _il) {
    m_pDC->IASetInputLayout(reinterpret_cast<amDXInputLayout*>(_il)->m_pVertexLayout);
  }

  //TODO: change setVB in DC to have stride & offset
  void amDXDeviceContext::setVertexBuffer(amVertexBuffer * _VB,
                                          const uint32 _stride,
                                          const uint32 _offset) {
    m_pDC->IASetVertexBuffers(0,
                              1,
                              &reinterpret_cast<amDXVertexBuffer*>(_VB)->m_pVB,
                              &_stride,
                              &_offset);
  }

  void amDXDeviceContext::setIndexBuffer(amIndexBuffer * _IB) {
    m_pDC->IASetIndexBuffer(reinterpret_cast<amDXIndexBuffer*>(_IB)->m_pIndexBuffer,
                            DXGI_FORMAT_R32_UINT, 
                            0);
  }

  void
  amDXDeviceContext::setPixelShader(amPixelShader* _PS) {
    m_pDC->PSSetShader(reinterpret_cast<amDXPixelShader*>(_PS)->m_ps, nullptr, 0);
  }

  void 
  amDXDeviceContext::setVertexShader(amVertexShader* _VS) {
    m_pDC->VSSetShader(reinterpret_cast<amDXVertexShader*>(_VS)->m_vs, nullptr, 0);
  }

  void amDXDeviceContext::setComputeShader(amComputeShader* _CS) {
    m_pDC->CSSetShader(reinterpret_cast<amDXComputeShader*>(_CS)->m_cs, nullptr, 0);
  }

  void amDXDeviceContext::clearDepthStencilView(amDepthStencilView * _pDSV, 
                                                uint32 _clearFlags,
                                                float _depth,
                                                uint8 _stencil) {
    m_pDC->ClearDepthStencilView(reinterpret_cast<amDXDepthStencilView*>(_pDSV)->m_pDSV, _clearFlags, _depth, _stencil);
  }

  void amDXDeviceContext::clearRenderTargetView(amRenderTargetView * _pRTV, amVector4* _color) {
    m_pDC->ClearRenderTargetView(reinterpret_cast<amDXRenderTargetView*>(_pRTV)->m_pRTV, _color->getVecArr());
  }

}
