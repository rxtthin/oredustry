#pragma once

#include "core/Libs.h"
#include "core/GLTexture.h"
#include "core/Font.h"
#include "core/Color.h"
#include "core/TextAlign.h"

namespace od::Renderer {
	enum class TextureShaderType {
		Normal,
		ColorSwap,
	};

	void Init();

	void Begin2D();
	void End2D();
	void BeginUI();
	void EndUI();

	void RenderQuad(const glm::f32vec2 &position, const glm::f32vec2 &size, const od::Color &color);
	void RenderQuadTextured(const glm::f32vec2 &position, const glm::f32vec2 &size, od::GLTexture *texture, const od::Color &color, TextureShaderType shaderType = TextureShaderType::Normal);
	void RenderText(const std::string &text, od::Font *font, const glm::f32vec2 &position, const od::Color &color, float scale=1, od::TextAlignHorizontal alignH=od::TextAlignHorizontal::Center, od::TextAlignVertical alignV=od::TextAlignVertical::Middle);

	extern uint32_t drawCalls;
}
