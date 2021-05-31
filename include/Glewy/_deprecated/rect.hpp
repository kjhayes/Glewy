#ifndef GLEWY_RECT_HPP
#define GLEWY_RECT_HPP

#include<Glewy/macros.hpp>
#include<Glewy/interfaces.hpp>

#include<SML/sml.hpp>

namespace gly
{
	enum RectVertex
	{
		BottomLeft = 0,
		BottomRight = 1,
		TopLeft = 2,
		TopRight = 3
	};
	
	class Rect 
	{
		protected:
			static sml::vec3 Unit_Square[4] = 
			{
				{0.0f,0.0f,0.0f},
				{1.0f,0.0f,0.0f},
				{0.0f,1.0f,0.0f},
				{1.0f,1.0f,0.0f}
			}
			
			
		
		public:
			Rect(const unsigned int& pivot = GLY_DEFAULT_PIVOT);
			
			Rect(const sml::vec2& position, const unsigned int& pivot = GLY_DEFAULT_PIVOT);
			Rect(const sml::vec2& position, const float& depth, const unsigned int& pivot = GLY_DEFAULT_PIVOT);
			Rect(const sml::vec3& location, const unsigned int& pivot = GLY_DEFAULT_PIVOT);
			
			Rect(const sml::vec2& position, const sml::vec2& dimensions, const unsigned int& pivot = GLY_DEFAULT_PIVOT);
			Rect(const sml::vec2& position, const float& depth, const sml::vec2& dimensions, const unsigned int& pivot = GLY_DEFAULT_PIVOT);
			Rect(const sml::vec3& location, const sml::vec2& dimensions, const unsigned int& pivot = GLY_DEFAULT_PIVOT);
			
			void SetPosition(const sml::vec2&);
			void SetLocation(const sml::vec3&);
			void SetDepth(const float&);
			void SetDimensions(const sml::vec2&);
			
			void SetPositionAndDimensions(const sml::vec2&, const sml::vec2&);
			void SetLocationAndDimensions(const sml::vec3&, const sml::vec2&);
			void SetPositionDepthAndDimensions(const sml::vec2&, const float&, const sml::vec2&);
			void SetDepthAndDimensions(const float&, const sml::vec2&);
			
			void SetPivot(const unsigned int&);
			
			sml::vec2 GetPosition() const;
			sml::vec3 GetLocation() const;
			float GetDepth() const;
			sml::vec2 GetDimensions() const;
		
			unsigned int GetPivot() const;
		
			sml::vec3 GetVertex(const unsigned int&) const;
			sml::vec3* GetVertices();//DO NOT EDIT POINTER
		
		protected:
			virtual void UpdateRect();
	};//class Rect
}//namespace gly
#endif