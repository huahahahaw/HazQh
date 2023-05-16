#include "HzPch.h"
#include "LayerStack.h"

namespace HazQh
{
	LayerStack::LayerStack()
	{
		
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
	}

	void LayerStack::PushOverLayer(Layer* Overlayer)
	{
		m_Layers.emplace_back(Overlayer);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverLayer(Layer* Overlayer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), Overlayer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}

}
