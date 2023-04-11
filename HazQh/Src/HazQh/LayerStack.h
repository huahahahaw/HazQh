#pragma once
#include "Core.h"
#include "Layer.h"

namespace HazQh
{
	class HAZQH_API  LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* Overlayer);
		void PopLayer(Layer* layer);
		void PopOverLayer(Layer* Overlayer);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};

}
