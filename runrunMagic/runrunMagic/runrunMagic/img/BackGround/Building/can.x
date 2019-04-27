xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 96;
 0.01051;1.11021;-0.32419;,
 0.23380;1.11021;-0.23170;,
 0.24457;1.03368;-0.24247;,
 0.01051;1.03368;-0.33942;,
 0.32629;1.11021;-0.00842;,
 0.34151;1.03368;-0.00842;,
 0.23380;1.11021;0.21487;,
 0.24457;1.03368;0.22564;,
 0.01051;1.11021;0.30736;,
 0.01051;1.03368;0.32258;,
 -0.21277;1.11021;0.21487;,
 -0.22354;1.03368;0.22564;,
 -0.30526;1.11021;-0.00842;,
 -0.32049;1.03368;-0.00842;,
 -0.21277;1.11021;-0.23170;,
 -0.22354;1.03368;-0.24247;,
 0.24457;0.19668;-0.24247;,
 0.01051;0.19668;-0.33942;,
 0.34151;0.19668;-0.00842;,
 0.24457;0.19668;0.22564;,
 0.01051;0.19668;0.32258;,
 -0.22354;0.19668;0.22564;,
 -0.32049;0.19668;-0.00842;,
 -0.22354;0.19668;-0.24247;,
 0.23380;0.12014;-0.23170;,
 0.01051;0.12014;-0.32419;,
 0.32629;0.12014;-0.00842;,
 0.23380;0.12014;0.21487;,
 0.01051;0.12014;0.30736;,
 -0.21277;0.12014;0.21487;,
 -0.30526;0.12014;-0.00842;,
 -0.21277;0.12014;-0.23170;,
 0.01050;1.08827;-0.32740;,
 0.23607;1.08827;-0.23397;,
 0.23607;1.06627;-0.23397;,
 0.01050;1.06627;-0.32740;,
 0.32950;1.08827;-0.00840;,
 0.32950;1.06627;-0.00840;,
 0.23607;1.08827;0.21717;,
 0.23607;1.06627;0.21717;,
 0.01050;1.08827;0.31060;,
 0.01050;1.06627;0.31060;,
 -0.21507;1.08827;0.21717;,
 -0.21507;1.06627;0.21717;,
 -0.30850;1.08827;-0.00840;,
 -0.30850;1.06627;-0.00840;,
 -0.21507;1.08827;-0.23397;,
 -0.21507;1.06627;-0.23397;,
 0.01050;1.08827;-0.32740;,
 0.01050;1.06627;-0.32740;,
 0.01050;1.08827;-0.00840;,
 0.01050;1.08827;-0.00840;,
 0.01050;1.08827;-0.00840;,
 0.01050;1.08827;-0.00840;,
 0.01050;1.08827;-0.00840;,
 0.01050;1.08827;-0.00840;,
 0.01050;1.08827;-0.00840;,
 0.01050;1.08827;-0.00840;,
 0.01050;1.06627;-0.00840;,
 0.01050;1.06627;-0.00840;,
 0.01050;1.06627;-0.00840;,
 0.01050;1.06627;-0.00840;,
 0.01050;0.12302;-0.32740;,
 0.23607;0.12302;-0.23397;,
 0.23607;0.10102;-0.23397;,
 0.01050;0.10102;-0.32740;,
 0.32950;0.12302;-0.00840;,
 0.32950;0.10102;-0.00840;,
 0.23607;0.12302;0.21717;,
 0.23607;0.10102;0.21717;,
 0.01050;0.12302;0.31060;,
 0.01050;0.10102;0.31060;,
 -0.21507;0.12302;0.21717;,
 -0.21507;0.10102;0.21717;,
 -0.30850;0.12302;-0.00840;,
 -0.30850;0.10102;-0.00840;,
 -0.21507;0.12302;-0.23397;,
 -0.21507;0.10102;-0.23397;,
 0.01050;0.12302;-0.32740;,
 0.01050;0.10102;-0.32740;,
 0.01050;0.12302;-0.00840;,
 0.01050;0.12302;-0.00840;,
 0.01050;0.12302;-0.00840;,
 0.01050;0.12302;-0.00840;,
 0.01050;0.12302;-0.00840;,
 0.01050;0.12302;-0.00840;,
 0.01050;0.12302;-0.00840;,
 0.01050;0.12302;-0.00840;,
 0.01050;0.10102;-0.00840;,
 0.01050;0.10102;-0.00840;,
 0.01050;0.10102;-0.00840;,
 0.01050;0.10102;-0.00840;,
 0.01050;0.10102;-0.00840;,
 0.01050;0.10102;-0.00840;,
 0.01050;0.10102;-0.00840;,
 0.01050;0.10102;-0.00840;;
 
 68;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,0,3,15;,
 4;3,2,16,17;,
 4;2,5,18,16;,
 4;5,7,19,18;,
 4;7,9,20,19;,
 4;9,11,21,20;,
 4;11,13,22,21;,
 4;13,15,23,22;,
 4;15,3,17,23;,
 4;17,16,24,25;,
 4;16,18,26,24;,
 4;18,19,27,26;,
 4;19,20,28,27;,
 4;20,21,29,28;,
 4;21,22,30,29;,
 4;22,23,31,30;,
 4;23,17,25,31;,
 4;32,33,34,35;,
 4;33,36,37,34;,
 4;36,38,39,37;,
 4;38,40,41,39;,
 4;40,42,43,41;,
 4;42,44,45,43;,
 4;44,46,47,45;,
 4;46,48,49,47;,
 3;50,33,32;,
 3;51,36,33;,
 3;52,38,36;,
 3;53,40,38;,
 3;54,42,40;,
 3;55,44,42;,
 3;56,46,44;,
 3;57,48,46;,
 3;58,35,34;,
 3;59,43,45;,
 3;60,45,47;,
 3;61,47,49;,
 4;62,63,64,65;,
 4;63,66,67,64;,
 4;66,68,69,67;,
 4;68,70,71,69;,
 4;70,72,73,71;,
 4;72,74,75,73;,
 4;74,76,77,75;,
 4;76,78,79,77;,
 3;80,63,62;,
 3;81,66,63;,
 3;82,68,66;,
 3;83,70,68;,
 3;84,72,70;,
 3;85,74,72;,
 3;86,76,74;,
 3;87,78,76;,
 3;88,65,64;,
 3;89,64,67;,
 3;90,67,69;,
 3;91,69,71;,
 3;92,71,73;,
 3;93,73,75;,
 3;94,75,77;,
 3;95,77,79;;
 
 MeshMaterialList {
  3;
  68;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  0,
  2,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.470000;0.470000;0.470000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.241569;0.229020;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  42;
  -0.000000;0.195090;-0.980785;,
  0.693520;0.195090;-0.693520;,
  0.980785;0.195091;0.000000;,
  0.693520;0.195090;0.693520;,
  -0.000000;0.195090;0.980785;,
  -0.693520;0.195090;0.693520;,
  -0.980785;0.195090;-0.000000;,
  -0.693520;0.195090;-0.693520;,
  -0.000000;0.098154;-0.995171;,
  0.703692;0.098154;-0.703692;,
  0.995171;0.098154;0.000000;,
  0.703692;0.098154;0.703692;,
  -0.000000;0.098154;0.995171;,
  -0.703692;0.098154;0.703692;,
  -0.995171;0.098154;-0.000000;,
  -0.703692;0.098154;-0.703692;,
  -0.000000;-0.098154;-0.995171;,
  0.703692;-0.098154;-0.703692;,
  0.995171;-0.098154;0.000000;,
  0.703692;-0.098154;0.703692;,
  -0.000000;-0.098154;0.995171;,
  -0.703692;-0.098154;0.703692;,
  -0.995171;-0.098154;-0.000000;,
  -0.703692;-0.098154;-0.703692;,
  -0.000000;-0.195090;-0.980785;,
  0.693520;-0.195090;-0.693520;,
  0.980785;-0.195090;0.000000;,
  0.693520;-0.195090;0.693520;,
  -0.000000;-0.195090;0.980785;,
  -0.693520;-0.195090;0.693520;,
  -0.980785;-0.195090;-0.000000;,
  -0.693520;-0.195090;-0.693520;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.707107;0.000000;0.707107;,
  -0.000000;0.000000;1.000000;,
  -0.707107;0.000000;0.707107;,
  -1.000000;0.000000;0.000000;,
  -0.707107;0.000000;-0.707107;,
  0.000000;-1.000000;-0.000000;;
  68;
  4;0,1,9,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,0,8,15;,
  4;8,9,17,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,8,16,23;,
  4;16,17,25,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,16,24,31;,
  4;33,34,34,33;,
  4;34,35,35,34;,
  4;35,36,36,35;,
  4;36,37,37,36;,
  4;37,38,38,37;,
  4;38,39,39,38;,
  4;39,40,40,39;,
  4;40,33,33,40;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  4;33,34,34,33;,
  4;34,35,35,34;,
  4;35,36,36,35;,
  4;36,37,37,36;,
  4;37,38,38,37;,
  4;38,39,39,38;,
  4;39,40,40,39;,
  4;40,33,33,40;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;32,32,32;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;;
 }
 MeshTextureCoords {
  96;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.187500;0.000000;,
  0.312500;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.687500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;,
  0.062500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.187500;0.000000;,
  0.312500;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.687500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
 MeshVertexColors {
  96;
  0;1.000000;1.000000;1.000000;1.000000;,
  1;1.000000;1.000000;1.000000;1.000000;,
  2;1.000000;1.000000;1.000000;1.000000;,
  3;1.000000;1.000000;1.000000;1.000000;,
  4;1.000000;1.000000;1.000000;1.000000;,
  5;1.000000;1.000000;1.000000;1.000000;,
  6;1.000000;1.000000;1.000000;1.000000;,
  7;1.000000;1.000000;1.000000;1.000000;,
  8;1.000000;1.000000;1.000000;1.000000;,
  9;1.000000;1.000000;1.000000;1.000000;,
  10;1.000000;1.000000;1.000000;1.000000;,
  11;1.000000;1.000000;1.000000;1.000000;,
  12;1.000000;1.000000;1.000000;1.000000;,
  13;1.000000;1.000000;1.000000;1.000000;,
  14;1.000000;1.000000;1.000000;1.000000;,
  15;1.000000;1.000000;1.000000;1.000000;,
  16;1.000000;1.000000;1.000000;1.000000;,
  17;1.000000;1.000000;1.000000;1.000000;,
  18;1.000000;1.000000;1.000000;1.000000;,
  19;1.000000;1.000000;1.000000;1.000000;,
  20;1.000000;1.000000;1.000000;1.000000;,
  21;1.000000;1.000000;1.000000;1.000000;,
  22;1.000000;1.000000;1.000000;1.000000;,
  23;1.000000;1.000000;1.000000;1.000000;,
  24;1.000000;1.000000;1.000000;1.000000;,
  25;1.000000;1.000000;1.000000;1.000000;,
  26;1.000000;1.000000;1.000000;1.000000;,
  27;1.000000;1.000000;1.000000;1.000000;,
  28;1.000000;1.000000;1.000000;1.000000;,
  29;1.000000;1.000000;1.000000;1.000000;,
  30;1.000000;1.000000;1.000000;1.000000;,
  31;1.000000;1.000000;1.000000;1.000000;,
  32;1.000000;1.000000;1.000000;1.000000;,
  33;1.000000;1.000000;1.000000;1.000000;,
  34;1.000000;1.000000;1.000000;1.000000;,
  35;1.000000;1.000000;1.000000;1.000000;,
  36;1.000000;1.000000;1.000000;1.000000;,
  37;1.000000;1.000000;1.000000;1.000000;,
  38;1.000000;1.000000;1.000000;1.000000;,
  39;1.000000;1.000000;1.000000;1.000000;,
  40;1.000000;1.000000;1.000000;1.000000;,
  41;1.000000;1.000000;1.000000;1.000000;,
  42;1.000000;1.000000;1.000000;1.000000;,
  43;1.000000;1.000000;1.000000;1.000000;,
  44;1.000000;1.000000;1.000000;1.000000;,
  45;1.000000;1.000000;1.000000;1.000000;,
  46;1.000000;1.000000;1.000000;1.000000;,
  47;1.000000;1.000000;1.000000;1.000000;,
  48;1.000000;1.000000;1.000000;1.000000;,
  49;1.000000;1.000000;1.000000;1.000000;,
  50;1.000000;1.000000;1.000000;1.000000;,
  51;1.000000;1.000000;1.000000;1.000000;,
  52;1.000000;1.000000;1.000000;1.000000;,
  53;1.000000;1.000000;1.000000;1.000000;,
  54;1.000000;1.000000;1.000000;1.000000;,
  55;1.000000;1.000000;1.000000;1.000000;,
  56;1.000000;1.000000;1.000000;1.000000;,
  57;1.000000;1.000000;1.000000;1.000000;,
  58;1.000000;1.000000;1.000000;1.000000;,
  59;1.000000;1.000000;1.000000;1.000000;,
  60;1.000000;1.000000;1.000000;1.000000;,
  61;1.000000;1.000000;1.000000;1.000000;,
  62;1.000000;1.000000;1.000000;1.000000;,
  63;1.000000;1.000000;1.000000;1.000000;,
  64;1.000000;1.000000;1.000000;1.000000;,
  65;1.000000;1.000000;1.000000;1.000000;,
  66;1.000000;1.000000;1.000000;1.000000;,
  67;1.000000;1.000000;1.000000;1.000000;,
  68;1.000000;1.000000;1.000000;1.000000;,
  69;1.000000;1.000000;1.000000;1.000000;,
  70;1.000000;1.000000;1.000000;1.000000;,
  71;1.000000;1.000000;1.000000;1.000000;,
  72;1.000000;1.000000;1.000000;1.000000;,
  73;1.000000;1.000000;1.000000;1.000000;,
  74;1.000000;1.000000;1.000000;1.000000;,
  75;1.000000;1.000000;1.000000;1.000000;,
  76;1.000000;1.000000;1.000000;1.000000;,
  77;1.000000;1.000000;1.000000;1.000000;,
  78;1.000000;1.000000;1.000000;1.000000;,
  79;1.000000;1.000000;1.000000;1.000000;,
  80;1.000000;1.000000;1.000000;1.000000;,
  81;1.000000;1.000000;1.000000;1.000000;,
  82;1.000000;1.000000;1.000000;1.000000;,
  83;1.000000;1.000000;1.000000;1.000000;,
  84;1.000000;1.000000;1.000000;1.000000;,
  85;1.000000;1.000000;1.000000;1.000000;,
  86;1.000000;1.000000;1.000000;1.000000;,
  87;1.000000;1.000000;1.000000;1.000000;,
  88;1.000000;1.000000;1.000000;1.000000;,
  89;1.000000;1.000000;1.000000;1.000000;,
  90;1.000000;1.000000;1.000000;1.000000;,
  91;1.000000;1.000000;1.000000;1.000000;,
  92;1.000000;1.000000;1.000000;1.000000;,
  93;1.000000;1.000000;1.000000;1.000000;,
  94;1.000000;1.000000;1.000000;1.000000;,
  95;1.000000;1.000000;1.000000;1.000000;;
 }
}
