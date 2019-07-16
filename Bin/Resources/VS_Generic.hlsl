/**
************************
*
*  Generic Vertex Shader
*
************************
*/
struct VS_INPUT 
{
   float4 Position : POSITION0;
   float2 TexCoords : TEXCOORD0; 
};

struct VS_OUTPUT 
{
   float4 Position : POSITION0;
   float2 TexCoords : TEXCOORD0;
};

VS_OUTPUT vs_main( VS_INPUT Input )
{
   VS_OUTPUT Output;

   Output.Position = Input.Position;
   Output.TexCoords = Input.TexCoords;
   
   return( Output );
}