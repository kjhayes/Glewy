#ifndef GLEWY_TRANSFORM_HPP
#define GLEWY_TRANSFORM_HPP

#include<SML/SML.hpp>

namespace gly
{
	class Transform
	{
		public:
			sml::vec3 position;
			sml::vec3 scale;
			
			Transform();

		protected:
			sml::mat4 matrix;
			virtual void UpdateMatrix();

		public:
			virtual sml::mat4 Matrix();
	};
}

#endif