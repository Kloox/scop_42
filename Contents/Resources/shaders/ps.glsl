#version 410 core
#define M_PI 3.14159265358979323846

out vec4 FragColor;

in vec2 TexCoord;
in vec3 ourColor;
in vec3 pos;
in vec2 vID;

// texture samplers
uniform sampler2D ourTexture;
uniform int t;
uniform int texMap;
uniform int colorType;
uniform int flip;


void main()
{
    if (t == 1) {

        float x = pos.x;
        float y = pos.y;
        float z = pos.z;

        if (texMap == 0) {

        int index = 0;
        float u = 0.f;
        float v = 0.f;



        float absX = abs(x);
        float absY = abs(y);
        float absZ = abs(z);
  
        int isXPositive = 0;
        if ( x > 0) {
            isXPositive = 1;
        }
        int isYPositive = 0;
        if ( y > 0) {
            isYPositive = 1;
        }
        int isZPositive = 0;
        if (z > 0) {
            isZPositive = 1;
        }
  
        float maxAxis = 0.f;
        float uc = 0.f;
        float vc = 0.f;
  
        // POSITIVE X
        if (isXPositive > 0 && absX >= absY && absX >= absZ) {
            // u (0 to 1) goes from +z to -z
            // v (0 to 1) goes from -y to +y
            maxAxis = absX;
            uc = -z;
            vc = y;
            index = 0;
        }
        // NEGATIVE X
        if (isXPositive == 0 && absX >= absY && absX >= absZ) {
            // u (0 to 1) goes from -z to +z
            // v (0 to 1) goes from -y to +y
            maxAxis = absX;
            uc = z;
            vc = y;
            index = 1;
        }
        // POSITIVE Y
        if (isYPositive > 0 && absY >= absX && absY >= absZ) {
            // u (0 to 1) goes from -x to +x
            // v (0 to 1) goes from +z to -z
            maxAxis = absY;
            uc = x;
            vc = -z;
            index = 2;
        }
        // NEGATIVE Y
        if (isYPositive == 0 && absY >= absX && absY >= absZ) {
            // u (0 to 1) goes from -x to +x
            // v (0 to 1) goes from -z to +z
            maxAxis = absY;
            uc = x;
            vc = z;
            index = 3;
        }
        // POSITIVE Z
        if (isZPositive > 0 && absZ >= absX && absZ >= absY) {
            // u (0 to 1) goes from -x to +x
            // v (0 to 1) goes from -y to +y
            maxAxis = absZ;
            uc = x;
            vc = y;
            index = 4;
        }
        // NEGATIVE Z
        if (isZPositive == 0 && absZ >= absX && absZ >= absY) {
            // u (0 to 1) goes from +x to -x
            // v (0 to 1) goes from -y to +y
            maxAxis = absZ;
            uc = -x;
            vc = y;
            index = 5;
        }

        // Convert range from -1 to 1 to 0 to 1
        u = 0.5f * (uc / maxAxis + 1.0f);
        v = 0.5f * (vc / maxAxis + 1.0f);
        FragColor = texture(ourTexture, vec2( u, v ) );


        } else if (texMap == 1) {
        // Spheric
        float r = sqrt(x*x+y*y+z*z);
        float theta = atan(y/x);
        float beta = acos(z/r);

        FragColor = texture(ourTexture, vec2( beta, theta ));

        } else if (texMap == 2) {

            // cylindrical texture mapping
            float p = sqrt(x*x+y*y);
            float tetha;

            if (x == 0 && y == 0) {
                tetha = 0;
            } else if (x >= 0) {
                tetha = asin(y/p);
            } else if (x > 0) {
                tetha = atan(y/x);
            } else if (x < 0) {
                tetha = -asin(y/p) + M_PI;
            }
            FragColor = texture(ourTexture, vec2( tetha, z ));
        } else if (texMap == 3) {
            if (flip == 0) {
                FragColor = texture(ourTexture, vec2(TexCoord.x + 0.0065, TexCoord.y) );
            } else {
                FragColor = texture(ourTexture, vec2(TexCoord.x + 0.0065, 1.0f - TexCoord.y) );
            }
        }


    } else {

        if (colorType == 0) {
            // basic grey faces color
			float r ,g ,b;
            int vle = gl_PrimitiveID % 5;

            float matColor[5];
            matColor[0] = 0.215f; matColor[1] = 0.195f; matColor[2] = 0.165f; matColor[3] = 0.145f; matColor[4] = 0.105f;

            r = matColor[vle];
            g = matColor[vle];
            b = matColor[vle];

		    FragColor = vec4(vec3(r, g, b), 1.0f);
		} else if (colorType == 1) {
            FragColor = vec4(ourColor, 1.0f);
        } else if (colorType == 2) {
            FragColor = vec4(vec3(0.110f, 0.080f, 0.255f), 1.0f);
        }
    }
}
