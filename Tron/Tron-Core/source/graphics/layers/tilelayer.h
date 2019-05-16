#pragma once

#include"layer.h"
#include"../batchrenderer2D.h"

namespace tron {
	namespace graphics {

		class TileLayer : public Layer
		{
		
		public:
			TileLayer( Shader* shader);
			~TileLayer();
		};


	}
}
