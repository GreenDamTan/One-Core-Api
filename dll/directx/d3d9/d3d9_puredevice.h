/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS ReactX
 * FILE:            dll/directx/d3d9/d3d9_haldevice.h
 * PURPOSE:         d3d9.dll internal device structures
 * PROGRAMERS:      Gregor Gullwi <gbrunmar (dot) ros (at) gmail (dot) com>
 */
#ifndef _D3D9_PUREDEVICE_H_
#define _D3D9_PUREDEVICE_H_

#include "d3d9_device.h"

typedef struct _D3D9PUREDEVICE
{
/* 0x0000 - 0x0000 */   DIRECT3DDEVICE9_INT BaseDevice;
/* 0x1f48 */    DWORD unknown002002; 
/* 0x1f4c */    DWORD unknown002003; 
/* 0x1f50 */    DWORD unknown002004; 
/* 0x1f54 */    DWORD unknown002005; 
/* 0x1f58 */    DWORD unknown002006; 
/* 0x1f5c */    DWORD unknown002007; 
/* 0x1f60 */    DWORD unknown002008; 
/* 0x1f64 */    DWORD unknown002009; 
/* 0x1f68 */    DWORD unknown002010; 
/* 0x1f6c */    DWORD unknown002011; 
/* 0x1f70 */    DWORD unknown002012; 
/* 0x1f74 */    DWORD unknown002013; 
/* 0x1f78 */    DWORD unknown002014; 
/* 0x1f7c */    DWORD unknown002015; 
/* 0x1f80 */    DWORD unknown002016; 
/* 0x1f84 */    DWORD unknown002017; 
/* 0x1f88 */    DWORD unknown002018; 
/* 0x1f8c */    DWORD unknown002019; 
/* 0x1f90 */    DWORD unknown002020; 
/* 0x1f94 */    DWORD unknown002021; 
/* 0x1f98 */    DWORD unknown002022; 
/* 0x1f9c */    DWORD unknown002023; 
/* 0x1fa0 */    DWORD unknown002024; 
/* 0x1fa4 */    DWORD unknown002025; 
/* 0x1fa8 - 0x1fe0 */   DWORD unknown002026; 
/* 0x1fac */    DWORD unknown002027; 
/* 0x1fb0 */    LPDWORD unknown002028; 
/* 0x1fb4 */    DWORD unknown002029; 
/* 0x1fb8 */    DWORD unknown002030; 
/* 0x1fbc */    DWORD unknown002031; 
/* 0x1fc0 */    DWORD unknown002032; 
/* 0x1fc4 */    DWORD unknown002033; 
/* 0x1fc8 */    DWORD unknown002034; 
/* 0x1fcc */    DWORD unknown002035; 
/* 0x1fd0 */    DWORD unknown002036; 
/* 0x1fd4 */    DWORD unknown002037; 
/* 0x1fd8 */    DWORD unknown002038; 
/* 0x1fdc */    DWORD unknown002039; 
/* 0x1fe0 */    DWORD unknown002040; 
/* 0x1fe4 */    DWORD unknown002041; 
/* 0x1fe8 */    DWORD unknown002042; 
/* 0x1fec */    DWORD unknown002043; 
/* 0x1ff0 */    DWORD unknown002044; 
/* 0x1ff4 */    DWORD unknown002045; 
/* 0x1ff8 */    DWORD unknown002046; 
/* 0x1ffc */    DWORD unknown002047; 
/* 0x2000 */    DWORD unknown002048; 
/* 0x2004 */    DWORD unknown002049; 
/* 0x2008 */    DWORD unknown002050; 
/* 0x200c */    DWORD unknown002051; 
/* 0x2010 */    DWORD unknown002052; 
/* 0x2014 */    DWORD unknown002053; 
/* 0x2018 */    DWORD unknown002054; 
/* 0x201c */    DWORD unknown002055; 
/* 0x2020 */    DWORD unknown002056; 
/* 0x2024 */    DWORD unknown002057; 
/* 0x2028 */    DWORD unknown002058; 
/* 0x202c */    DWORD unknown002059; 
/* 0x2030 */    DWORD unknown002060; 
/* 0x2034 */    DWORD unknown002061; 
/* 0x2038 */    DWORD unknown002062; 
/* 0x203c */    DWORD unknown002063; 
/* 0x2040 */    DWORD unknown002064; 
/* 0x2044 */    DWORD unknown002065; 
/* 0x2048 */    DWORD unknown002066; 
/* 0x204c */    DWORD unknown002067; 
/* 0x2050 */    DWORD unknown002068; 
/* 0x2054 */    DWORD unknown002069; 
/* 0x2058 */    DWORD unknown002070; 
/* 0x205c */    DWORD unknown002071; 
/* 0x2060 */    DWORD unknown002072; 
/* 0x2064 */    DWORD unknown002073; 
/* 0x2068 */    DWORD unknown002074; 
/* 0x206c */    DWORD unknown002075; 
/* 0x2070 */    DWORD unknown002076; 
/* 0x2074 */    DWORD unknown002077; 
/* 0x2078 */    DWORD unknown002078; 
/* 0x207c */    DWORD unknown002079; 
/* 0x2080 */    DWORD unknown002080; 
/* 0x2084 */    DWORD unknown002081; 
/* 0x2088 */    DWORD unknown002082; 
/* 0x208c */    DWORD unknown002083; // SurfaceManager?
/* 0x2090 */    DWORD unknown002084; 
/* 0x2094 */    DWORD unknown002085; 
/* 0x2098 */    DWORD unknown002086; 
/* 0x209c */    DWORD unknown002087; 
/* 0x20a0 */    DWORD unknown002088; 
/* 0x20a4 */    DWORD unknown002089; 
/* 0x20a8 */    DWORD unknown002090; 
/* 0x20ac */    DWORD unknown002091; 
/* 0x20b0 */    DWORD unknown002092; 
/* 0x20b4 */    DWORD unknown002093; 
/* 0x20b8 */    DWORD unknown002094; 
/* 0x20bc */    DWORD unknown002095; 
/* 0x20c0 */    DWORD unknown002096; 
/* 0x20c4 */    DWORD unknown002097; 
/* 0x20c8 */    DWORD unknown002098; 
/* 0x20cc */    DWORD unknown002099; 
/* 0x20d0 */    DWORD unknown002100; // VSOutputDecl?
/* 0x20d4 */    DWORD unknown002101; 
/* 0x20d8 */    DWORD unknown002102; 
/* 0x20dc */    DWORD unknown002103; 
/* 0x20e0 */    DWORD unknown002104; 
/* 0x20e4 */    DWORD unknown002105; 
/* 0x20e8 */    DWORD unknown002106; 
/* 0x20ec */    DWORD unknown002107; 
/* 0x20f0 */    DWORD unknown002108; 
/* 0x20f4 */    DWORD unknown002109; 
/* 0x20f8 */    DWORD unknown002110; 
/* 0x20fc */    DWORD unknown002111; 
/* 0x2100 */    DWORD unknown002112;
/* 0x2104 */    DWORD unknown002113;
/* 0x2108 */    DWORD unknown002114;
/* 0x210c */    DWORD unknown002115;
/* 0x2110 */    DWORD unknown002116;
/* 0x2114 */    DWORD unknown002117;
/* 0x2118 */    DWORD unknown002118;
/* 0x211c */    DWORD unknown002119;
/* 0x2120 */    DWORD unknown002120;
/* 0x2124 */    DWORD unknown002121;
/* 0x2128 */    DWORD unknown002122;
/* 0x212c */    DWORD unknown002123;
/* 0x2130 */    DWORD unknown002124;
/* 0x2134 */    DWORD unknown002125;
/* 0x2138 */    DWORD unknown002126;
/* 0x213c */    DWORD unknown002127;
/* 0x2140 */    DWORD unknown002128;
/* 0x2144 */    DWORD unknown002129;
/* 0x2148 */    DWORD unknown002130;
/* 0x214c */    DWORD unknown002131;
/* 0x2150 */    DWORD unknown002132;
/* 0x2154 */    DWORD unknown002133;
/* 0x2158 */    DWORD unknown002134;
/* 0x215c */    DWORD unknown002135;
/* 0x2160 */    DWORD unknown002136;
/* 0x2164 */    DWORD unknown002137;
/* 0x2168 */    DWORD unknown002138;
/* 0x216c */    DWORD unknown002139;
/* 0x2170 */    DWORD unknown002140;
/* 0x2174 */    DWORD unknown002141;
/* 0x2178 */    DWORD unknown002142;
/* 0x217c */    DWORD unknown002143;
/* 0x2180 */    DWORD unknown002144;
/* 0x2184 */    DWORD unknown002145;
/* 0x2188 */    DWORD unknown002146;
/* 0x218c */    DWORD unknown002147;
/* 0x2190 */    DWORD unknown002148;
/* 0x2194 */    DWORD unknown002149;
/* 0x2198 */    DWORD unknown002150;
/* 0x219c */    DWORD unknown002151;
/* 0x21a0 */    DWORD unknown002152;
/* 0x21a4 */    DWORD unknown002153;
/* 0x21a8 */    DWORD unknown002154;
/* 0x21ac */    DWORD unknown002155;
/* 0x21b0 */    DWORD unknown002156;
/* 0x21b4 */    DWORD unknown002157;
/* 0x21b8 */    DWORD unknown002158;
/* 0x21bc */    DWORD unknown002159;
/* 0x21c0 */    DWORD unknown002160;
/* 0x21c4 */    DWORD unknown002161;
/* 0x21c8 */    DWORD unknown002162;
/* 0x21cc */    DWORD unknown002163;
/* 0x21d0 */    DWORD unknown002164;
/* 0x21d4 */    DWORD unknown002165;
/* 0x21d8 */    DWORD unknown002166;
/* 0x21dc */    DWORD unknown002167;
/* 0x21e0 */    DWORD unknown002168;
/* 0x21e4 */    DWORD unknown002169;
/* 0x21e8 */    DWORD unknown002170;
/* 0x21ec */    DWORD unknown002171;
/* 0x21f0 */    DWORD unknown002172;
/* 0x21f4 */    DWORD unknown002173;
/* 0x21f8 */    DWORD unknown002174;
/* 0x21fc */    DWORD unknown002175;
/* 0x2200 */    DWORD unknown002176;
/* 0x2204 */    DWORD unknown002177;
/* 0x2208 */    DWORD unknown002178;
/* 0x220c */    DWORD unknown002179;
/* 0x2210 */    DWORD unknown002180;
/* 0x2214 */    DWORD unknown002181;
/* 0x2218 */    DWORD unknown002182;
/* 0x221c */    DWORD unknown002183;
/* 0x2220 */    DWORD unknown002184;
/* 0x2224 */    DWORD unknown002185;
/* 0x2228 */    DWORD unknown002186;
/* 0x222c */    DWORD unknown002187;
/* 0x2230 */    DWORD unknown002188;
/* 0x2234 */    DWORD unknown002189;
/* 0x2238 */    DWORD unknown002190;
/* 0x223c */    DWORD unknown002191;
/* 0x2240 */    DWORD unknown002192;
/* 0x2244 */    DWORD unknown002193;
/* 0x2248 */    DWORD unknown002194;
/* 0x224c */    DWORD unknown002195;
/* 0x2250 */    DWORD unknown002196;
/* 0x2254 */    DWORD unknown002197;
/* 0x2258 */    DWORD unknown002198;
/* 0x225c */    DWORD unknown002199;
/* 0x2260 */    DWORD unknown002200;
/* 0x2264 */    DWORD unknown002201;
/* 0x2268 */    DWORD unknown002202;
/* 0x226c */    DWORD unknown002203;
/* 0x2270 */    DWORD unknown002204;
/* 0x2274 */    DWORD unknown002205;
/* 0x2278 */    DWORD unknown002206;
/* 0x227c */    DWORD unknown002207;
/* 0x2280 */    DWORD unknown002208;
/* 0x2284 */    DWORD unknown002209;
/* 0x2288 */    DWORD unknown002210;
/* 0x228c */    DWORD unknown002211;
/* 0x2290 */    DWORD unknown002212;
/* 0x2294 */    DWORD unknown002213;
/* 0x2298 */    DWORD unknown002214;
/* 0x229c */    DWORD unknown002215;
/* 0x22a0 */    DWORD unknown002216;
/* 0x22a4 */    DWORD unknown002217;
/* 0x22a8 */    DWORD unknown002218;
/* 0x22ac */    DWORD unknown002219;
/* 0x22b0 */    DWORD unknown002220;
/* 0x22b4 */    DWORD unknown002221;
/* 0x22b8 */    DWORD unknown002222;
/* 0x22bc */    DWORD unknown002223;
/* 0x22c0 */    DWORD unknown002224;
/* 0x22c4 */    DWORD unknown002225;
/* 0x22c8 */    DWORD unknown002226;
/* 0x22cc */    DWORD unknown002227;
/* 0x22d0 */    DWORD unknown002228;
/* 0x22d4 */    DWORD unknown002229;
/* 0x22d8 */    DWORD unknown002230;
/* 0x22dc */    DWORD unknown002231;
/* 0x22e0 */    DWORD unknown002232;
/* 0x22e4 */    DWORD unknown002233;
/* 0x22e8 */    DWORD unknown002234;
/* 0x22ec */    DWORD unknown002235;
/* 0x22f0 */    DWORD unknown002236;
/* 0x22f4 */    DWORD unknown002237;
/* 0x22f8 */    DWORD unknown002238;
/* 0x22fc */    DWORD unknown002239;
/* 0x2300 */    DWORD unknown002240;
/* 0x2304 */    DWORD unknown002241;
/* 0x2308 */    DWORD unknown002242;
/* 0x230c */    DWORD unknown002243;
/* 0x2310 */    DWORD unknown002244;
/* 0x2314 */    DWORD unknown002245;
/* 0x2318 */    DWORD unknown002246;
/* 0x231c */    DWORD unknown002247;
/* 0x2320 */    DWORD unknown002248;
/* 0x2324 */    DWORD unknown002249;
/* 0x2328 */    DWORD unknown002250;
/* 0x232c */    DWORD unknown002251;
/* 0x2330 */    DWORD unknown002252;
/* 0x2334 */    DWORD unknown002253;
/* 0x2338 */    DWORD unknown002254;
/* 0x233c */    DWORD unknown002255;
/* 0x2340 */    DWORD unknown002256;
/* 0x2344 */    DWORD unknown002257;
/* 0x2348 */    DWORD unknown002258;
/* 0x234c */    DWORD unknown002259;
/* 0x2350 */    DWORD unknown002260;
/* 0x2354 */    DWORD unknown002261;
/* 0x2358 */    DWORD unknown002262;
/* 0x235c */    DWORD unknown002263;
/* 0x2360 */    DWORD unknown002264;
/* 0x2364 */    DWORD unknown002265;
/* 0x2368 */    DWORD unknown002266;
/* 0x236c */    DWORD unknown002267;
/* 0x2370 */    DWORD unknown002268;
/* 0x2374 */    DWORD unknown002269;
/* 0x2378 */    DWORD unknown002270;
/* 0x237c */    DWORD unknown002271;
/* 0x2380 */    DWORD unknown002272;
/* 0x2384 */    DWORD unknown002273;
/* 0x2388 */    DWORD unknown002274;
/* 0x238c */    DWORD unknown002275;
/* 0x2390 */    DWORD unknown002276;
/* 0x2394 */    DWORD unknown002277;
/* 0x2398 */    DWORD unknown002278;
/* 0x239c */    DWORD unknown002279;
/* 0x23a0 */    DWORD unknown002280;
/* 0x23a4 */    DWORD unknown002281;
/* 0x23a8 */    DWORD unknown002282;
/* 0x23ac */    DWORD unknown002283;
/* 0x23b0 */    DWORD unknown002284;
/* 0x23b4 */    DWORD unknown002285;
/* 0x23b8 */    DWORD unknown002286;
/* 0x23bc */    DWORD unknown002287;
/* 0x23c0 */    DWORD unknown002288;
/* 0x23c4 */    DWORD unknown002289;
/* 0x23c8 */    DWORD unknown002290;
/* 0x23cc */    DWORD unknown002291;
/* 0x23d0 */    DWORD unknown002292;
/* 0x23d4 */    DWORD unknown002293;
/* 0x23d8 */    DWORD unknown002294;
/* 0x23dc */    DWORD unknown002295;
/* 0x23e0 */    DWORD unknown002296;
/* 0x23e4 */    DWORD unknown002297;
/* 0x23e8 */    DWORD unknown002298;
/* 0x23ec */    DWORD unknown002299;
/* 0x23f0 */    DWORD unknown002300;
/* 0x23f4 */    DWORD unknown002301;
/* 0x23f8 */    DWORD unknown002302;
/* 0x23fc */    DWORD unknown002303;
/* 0x2400 */    DWORD unknown002304;
/* 0x2404 */    DWORD unknown002305;
/* 0x2408 */    DWORD unknown002306;
/* 0x240c */    DWORD unknown002307;
/* 0x2410 */    DWORD unknown002308;
/* 0x2414 */    DWORD unknown002309;
/* 0x2418 */    DWORD unknown002310;
/* 0x241c */    DWORD unknown002311;
/* 0x2420 */    DWORD unknown002312;
/* 0x2424 */    DWORD unknown002313;
/* 0x2428 */    DWORD unknown002314;
/* 0x242c */    DWORD unknown002315;
/* 0x2430 */    DWORD unknown002316;
/* 0x2434 */    DWORD unknown002317;
} D3D9PUREDEVICE, FAR *LPD3D9PUREDEVICE;

/* IDirect3D9Device public interface */
HRESULT WINAPI IDirect3DDevice9Pure_SetRenderTarget(LPDIRECT3DDEVICE9 iface, DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget);
HRESULT WINAPI IDirect3DDevice9Pure_GetRenderTarget(LPDIRECT3DDEVICE9 iface, DWORD RenderTargetIndex,IDirect3DSurface9** ppRenderTarget);
HRESULT WINAPI IDirect3DDevice9Pure_SetDepthStencilSurface(LPDIRECT3DDEVICE9 iface, IDirect3DSurface9* pNewZStencil);
HRESULT WINAPI IDirect3DDevice9Pure_GetDepthStencilSurface(LPDIRECT3DDEVICE9 iface, IDirect3DSurface9** ppZStencilSurface);
HRESULT WINAPI IDirect3DDevice9Pure_BeginScene(LPDIRECT3DDEVICE9 iface);
HRESULT WINAPI IDirect3DDevice9Pure_EndScene(LPDIRECT3DDEVICE9 iface);
HRESULT WINAPI IDirect3DDevice9Pure_Clear(LPDIRECT3DDEVICE9 iface, DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil);
HRESULT WINAPI IDirect3DDevice9Pure_SetTransform(LPDIRECT3DDEVICE9 iface, D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix);
HRESULT WINAPI IDirect3DDevice9Pure_GetTransform(LPDIRECT3DDEVICE9 iface, D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix);
HRESULT WINAPI IDirect3DDevice9Pure_MultiplyTransform(LPDIRECT3DDEVICE9 iface, D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix);
HRESULT WINAPI IDirect3DDevice9Pure_SetViewport(LPDIRECT3DDEVICE9 iface, CONST D3DVIEWPORT9* pViewport);
HRESULT WINAPI IDirect3DDevice9Pure_GetViewport(LPDIRECT3DDEVICE9 iface, D3DVIEWPORT9* pViewport);
HRESULT WINAPI IDirect3DDevice9Pure_SetMaterial(LPDIRECT3DDEVICE9 iface, CONST D3DMATERIAL9* pMaterial);
HRESULT WINAPI IDirect3DDevice9Pure_GetMaterial(LPDIRECT3DDEVICE9 iface, D3DMATERIAL9* pMaterial);
HRESULT WINAPI IDirect3DDevice9Pure_SetLight(LPDIRECT3DDEVICE9 iface, DWORD Index, CONST D3DLIGHT9* pLight);
HRESULT WINAPI IDirect3DDevice9Pure_GetLight(LPDIRECT3DDEVICE9 iface, DWORD Index, D3DLIGHT9* pLight);
HRESULT WINAPI IDirect3DDevice9Pure_LightEnable(LPDIRECT3DDEVICE9 iface, DWORD Index, BOOL Enable);
HRESULT WINAPI IDirect3DDevice9Pure_GetLightEnable(LPDIRECT3DDEVICE9 iface, DWORD Index, BOOL* pEnable);
HRESULT WINAPI IDirect3DDevice9Pure_SetClipPlane(LPDIRECT3DDEVICE9 iface, DWORD Index, CONST float* pPlane);
HRESULT WINAPI IDirect3DDevice9Pure_GetClipPlane(LPDIRECT3DDEVICE9 iface, DWORD Index, float* pPlane);
HRESULT WINAPI IDirect3DDevice9Pure_SetRenderState(LPDIRECT3DDEVICE9 iface, D3DRENDERSTATETYPE State, DWORD Value);
HRESULT WINAPI IDirect3DDevice9Pure_GetRenderState(LPDIRECT3DDEVICE9 iface, D3DRENDERSTATETYPE State, DWORD* pValue);
HRESULT WINAPI IDirect3DDevice9Pure_CreateStateBlock(LPDIRECT3DDEVICE9 iface, D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB);
HRESULT WINAPI IDirect3DDevice9Pure_BeginStateBlock(LPDIRECT3DDEVICE9 iface);
HRESULT WINAPI IDirect3DDevice9Pure_EndStateBlock(LPDIRECT3DDEVICE9 iface, IDirect3DStateBlock9** ppSB);
HRESULT WINAPI IDirect3DDevice9Pure_SetClipStatus(LPDIRECT3DDEVICE9 iface, CONST D3DCLIPSTATUS9* pClipStatus);
HRESULT WINAPI IDirect3DDevice9Pure_GetClipStatus(LPDIRECT3DDEVICE9 iface, D3DCLIPSTATUS9* pClipStatus);
HRESULT WINAPI IDirect3DDevice9Pure_GetTexture(LPDIRECT3DDEVICE9 iface, DWORD Stage, IDirect3DBaseTexture9** ppTexture);
HRESULT WINAPI IDirect3DDevice9Pure_SetTexture(LPDIRECT3DDEVICE9 iface, DWORD Stage, IDirect3DBaseTexture9* pTexture);
HRESULT WINAPI IDirect3DDevice9Pure_GetTextureStageState(LPDIRECT3DDEVICE9 iface, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue);
HRESULT WINAPI IDirect3DDevice9Pure_SetTextureStageState(LPDIRECT3DDEVICE9 iface, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value);
HRESULT WINAPI IDirect3DDevice9Pure_GetSamplerState(LPDIRECT3DDEVICE9 iface, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue);
HRESULT WINAPI IDirect3DDevice9Pure_SetSamplerState(LPDIRECT3DDEVICE9 iface, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value);
HRESULT WINAPI IDirect3DDevice9Pure_ValidateDevice(LPDIRECT3DDEVICE9 iface, DWORD* pNumPasses);
HRESULT WINAPI IDirect3DDevice9Pure_SetPaletteEntries(LPDIRECT3DDEVICE9 iface, UINT PaletteNumber, CONST PALETTEENTRY* pEntries);
HRESULT WINAPI IDirect3DDevice9Pure_GetPaletteEntries(LPDIRECT3DDEVICE9 iface, UINT PaletteNumber, PALETTEENTRY* pEntries);
HRESULT WINAPI IDirect3DDevice9Pure_SetCurrentTexturePalette(LPDIRECT3DDEVICE9 iface, UINT PaletteNumber);
HRESULT WINAPI IDirect3DDevice9Pure_GetCurrentTexturePalette(LPDIRECT3DDEVICE9 iface, UINT* pPaletteNumber);
HRESULT WINAPI IDirect3DDevice9Pure_SetScissorRect(LPDIRECT3DDEVICE9 iface, CONST RECT* pRect);
HRESULT WINAPI IDirect3DDevice9Pure_GetScissorRect(LPDIRECT3DDEVICE9 iface, RECT* pRect);
HRESULT WINAPI IDirect3DDevice9Pure_SetSoftwareVertexProcessing(LPDIRECT3DDEVICE9 iface, BOOL bSoftware);
BOOL WINAPI IDirect3DDevice9Pure_GetSoftwareVertexProcessing(LPDIRECT3DDEVICE9 iface);
HRESULT WINAPI IDirect3DDevice9Pure_SetNPatchMode(LPDIRECT3DDEVICE9 iface, float nSegments);
float WINAPI IDirect3DDevice9Pure_GetNPatchMode(LPDIRECT3DDEVICE9 iface);
HRESULT WINAPI IDirect3DDevice9Pure_DrawPrimitive(LPDIRECT3DDEVICE9 iface, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount);
HRESULT WINAPI IDirect3DDevice9Pure_DrawIndexedPrimitive(LPDIRECT3DDEVICE9 iface, D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount);
HRESULT WINAPI IDirect3DDevice9Pure_DrawPrimitiveUP(LPDIRECT3DDEVICE9 iface, D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride);
HRESULT WINAPI IDirect3DDevice9Pure_DrawIndexedPrimitiveUP(LPDIRECT3DDEVICE9 iface, D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride);
HRESULT WINAPI IDirect3DDevice9Pure_ProcessVertices(LPDIRECT3DDEVICE9 iface, UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags);
HRESULT WINAPI IDirect3DDevice9Pure_CreateVertexDeclaration(LPDIRECT3DDEVICE9 iface, CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl);
HRESULT WINAPI IDirect3DDevice9Pure_SetVertexDeclaration(LPDIRECT3DDEVICE9 iface, IDirect3DVertexDeclaration9* pDecl);
HRESULT WINAPI IDirect3DDevice9Pure_GetVertexDeclaration(LPDIRECT3DDEVICE9 iface, IDirect3DVertexDeclaration9** ppDecl);
HRESULT WINAPI IDirect3DDevice9Pure_SetFVF(LPDIRECT3DDEVICE9 iface, DWORD FVF);
HRESULT WINAPI IDirect3DDevice9Pure_GetFVF(LPDIRECT3DDEVICE9 iface, DWORD* pFVF);
HRESULT WINAPI IDirect3DDevice9Pure_CreateVertexShader(LPDIRECT3DDEVICE9 iface, CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader);
HRESULT WINAPI IDirect3DDevice9Pure_SetVertexShader(LPDIRECT3DDEVICE9 iface, IDirect3DVertexShader9* pShader);
HRESULT WINAPI IDirect3DDevice9Pure_GetVertexShader(LPDIRECT3DDEVICE9 iface, IDirect3DVertexShader9** ppShader);
HRESULT WINAPI IDirect3DDevice9Pure_SetVertexShaderConstantF(LPDIRECT3DDEVICE9 iface, UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount);
HRESULT WINAPI IDirect3DDevice9Pure_GetVertexShaderConstantF(LPDIRECT3DDEVICE9 iface, UINT StartRegister, float* pConstantData, UINT Vector4fCount);
HRESULT WINAPI IDirect3DDevice9Pure_SetVertexShaderConstantI(LPDIRECT3DDEVICE9 iface, UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount);
HRESULT WINAPI IDirect3DDevice9Pure_GetVertexShaderConstantI(LPDIRECT3DDEVICE9 iface, UINT StartRegister, int* pConstantData, UINT Vector4iCount);
HRESULT WINAPI IDirect3DDevice9Pure_SetVertexShaderConstantB(LPDIRECT3DDEVICE9 iface, UINT StartRegister, CONST BOOL* pConstantData, UINT BoolCount);
HRESULT WINAPI IDirect3DDevice9Pure_GetVertexShaderConstantB(LPDIRECT3DDEVICE9 iface, UINT StartRegister, BOOL* pConstantData, UINT BoolCount);
HRESULT WINAPI IDirect3DDevice9Pure_SetStreamSource(LPDIRECT3DDEVICE9 iface, UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride);
HRESULT WINAPI IDirect3DDevice9Pure_GetStreamSource(LPDIRECT3DDEVICE9 iface, UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride);
HRESULT WINAPI IDirect3DDevice9Pure_SetStreamSourceFreq(LPDIRECT3DDEVICE9 iface, UINT StreamNumber,UINT Setting);
HRESULT WINAPI IDirect3DDevice9Pure_GetStreamSourceFreq(LPDIRECT3DDEVICE9 iface, UINT StreamNumber, UINT* pSetting);
HRESULT WINAPI IDirect3DDevice9Pure_SetIndices(LPDIRECT3DDEVICE9 iface, IDirect3DIndexBuffer9* pIndexData);
HRESULT WINAPI IDirect3DDevice9Pure_GetIndices(LPDIRECT3DDEVICE9 iface, IDirect3DIndexBuffer9** ppIndexData);
HRESULT WINAPI IDirect3DDevice9Pure_CreatePixelShader(LPDIRECT3DDEVICE9 iface, CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader);
HRESULT WINAPI IDirect3DDevice9Pure_SetPixelShader(LPDIRECT3DDEVICE9 iface, IDirect3DPixelShader9* pShader);
HRESULT WINAPI IDirect3DDevice9Pure_GetPixelShader(LPDIRECT3DDEVICE9 iface, IDirect3DPixelShader9** ppShader);
HRESULT WINAPI IDirect3DDevice9Pure_SetPixelShaderConstantF(LPDIRECT3DDEVICE9 iface, UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount);
HRESULT WINAPI IDirect3DDevice9Pure_GetPixelShaderConstantF(LPDIRECT3DDEVICE9 iface, UINT StartRegister, float* pConstantData, UINT Vector4fCount);
HRESULT WINAPI IDirect3DDevice9Pure_SetPixelShaderConstantI(LPDIRECT3DDEVICE9 iface, UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount);
HRESULT WINAPI IDirect3DDevice9Pure_GetPixelShaderConstantI(LPDIRECT3DDEVICE9 iface, UINT StartRegister, int* pConstantData, UINT Vector4iCount);
HRESULT WINAPI IDirect3DDevice9Pure_SetPixelShaderConstantB(LPDIRECT3DDEVICE9 iface, UINT StartRegister, CONST BOOL* pConstantData, UINT BoolCount);
HRESULT WINAPI IDirect3DDevice9Pure_GetPixelShaderConstantB(LPDIRECT3DDEVICE9 iface, UINT StartRegister, BOOL* pConstantData, UINT BoolCount);
HRESULT WINAPI IDirect3DDevice9Pure_DrawRectPatch(LPDIRECT3DDEVICE9 iface, UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo);
HRESULT WINAPI IDirect3DDevice9Pure_DrawTriPatch(LPDIRECT3DDEVICE9 iface, UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo);
HRESULT WINAPI IDirect3DDevice9Pure_DeletePatch(LPDIRECT3DDEVICE9 iface, UINT Handle);
HRESULT WINAPI IDirect3DDevice9Pure_CreateQuery(LPDIRECT3DDEVICE9 iface, D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery);

#endif // _D3D9_PUREDEVICE_H_
