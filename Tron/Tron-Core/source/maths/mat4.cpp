#include"mat4.h"

namespace tron {
	namespace maths {

		mat4::mat4()
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0.0f;
			}
		}
			
		mat4::mat4(float diagonal)
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0.0f;
			}

			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		mat4 mat4::identity()
		{
			return mat4(1.0f);
		}

		
	

	}
}