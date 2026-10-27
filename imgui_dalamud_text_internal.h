// BEGIN DALAMUD CUSTOM [FONT]

#ifndef IMGUI_VERSION
#error "include imgui_internal.h instead."
#endif
#ifdef IMGUI_DALAMUD_TEXT_INTERNAL_H_INCLUDED
#error "include imgui_internal.h instead."
#endif
#define IMGUI_DALAMUD_TEXT_INTERNAL_H_INCLUDED

struct ImDrawShapeTexUvs
{
    ImVec2          WhitePixel;
    ImVec4          Lines[IM_DRAWLIST_TEX_LINES_WIDTH_MAX + 1 + IM_DRAWLIST_TEX_LINES_DETAILED_WIDTH_COUNT];   // (u0, u1, v, 1 / width) per baked line width
    ImVec4          Corners[IM_DRAWLIST_TEX_CORNERS_ROUNDING_MAX * IM_DRAWLIST_TEX_CORNERS_THICKNESS_MAX];     // (u0, v0, u1, v1) per rounding/thickness
    ImVec2          MouseCursorsOrigin;         // Coordinates of the cursor bitmaps, in pixels.
    ImVec2          TexUvScale;                 // 1 / texture size.
};

enum ImGuiInputTextMove
{
    ImGuiInputTextMove_Left,
    ImGuiInputTextMove_Right,
    ImGuiInputTextMove_Up,
    ImGuiInputTextMove_Down,
    ImGuiInputTextMove_PageUp,
    ImGuiInputTextMove_PageDown,
    ImGuiInputTextMove_LineStart,
    ImGuiInputTextMove_LineEnd,
};

namespace ImGui
{
    // Populates ImTextDesc from font size, pixel density, and active InputText password and plain-text flags, reading from draw_list or GImGui when draw_list is NULL.
    IMGUI_API void          GetTextDesc(ImTextDesc* out_desc, float wrap_width = 0.0f, ImTextLayoutFlags flags = 0, const ImDrawList* draw_list = NULL);

    // Release *out_layout after use. desc NULL = GetTextDesc(). text_end NULL = zero-terminated. On failure, *out_layout is NULL.
    IMGUI_API ImHRESULT     CreateTextLayout(ImFont* font, const ImTextDesc* desc, const char* text, const char* text_end, ImTextLayout** out_layout);

    // desc NULL = GetTextDesc().
    IMGUI_API ImVec2        CalcTextSizeEx(ImFont* font, const ImTextDesc* desc, const char* text_begin, const char* text_end_display, const char* text_end, const char** out_remaining = NULL, ImVec2* out_offset = NULL);

    // Calculates using the current font.
    IMGUI_API const char*   CalcWrappedLineEnd(const char* line_begin, const char* text_end, float wrap_width, ImTextLayoutFlags flags = ImTextLayoutFlags_WrapKeepBlanks);

    IMGUI_API void          RenderTextEllipsisEx(ImDrawList* draw_list, const ImVec2& pos_min, const ImVec2& pos_max, float ellipsis_max_x, const char* text, const char* text_end, const ImVec2* text_size_if_known, const ImTextTransform* transform, const ImVec2& transformed_pos_min);

    IMGUI_API ImVec2i       GetShapeTexDataSize();
    IMGUI_API void          RenderShapeTexData(ImTextureData* tex, ImDrawShapeTexUvs* out_uvs = NULL);

    IMGUI_API ImTextureData* CreateShapeTexture(ImDrawListSharedData* shared_data, int width, int height);
    IMGUI_API void          DestroyShapeTexture(ImDrawListSharedData* shared_data);
    IMGUI_API bool          GetMouseCursorTexData(ImGuiMouseCursor cursor_type, ImVec2* out_offset, ImVec2* out_size, ImVec2 out_uv_border[2], ImVec2 out_uv_fill[2]);
} // namespace ImGui

// END DALAMUD CUSTOM [FONT]
