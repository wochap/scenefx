#ifndef _FX_SHADERS_H
#define _FX_SHADERS_H

#include <GLES2/gl2.h>
#include <stdbool.h>

struct fx_renderer;

GLuint compile_shader(GLuint type, const GLchar *src);

GLuint link_program(const GLchar *frag_src);

bool check_gl_ext(const char *exts, const char *ext);

void load_gl_proc(void *proc_ptr, const char *name);

enum fx_tex_shader_source {
	SHADER_SOURCE_TEXTURE_RGBA = 1,
	SHADER_SOURCE_TEXTURE_RGBX = 2,
	SHADER_SOURCE_TEXTURE_EXTERNAL = 3,
};

struct quad_shader {
	GLuint program;
	GLint proj;
	GLint color;
	GLint pos_attrib;
};

struct tex_shader {
	GLuint program;
	GLint proj;
	GLint tex_proj;
	GLint tex;
	GLint alpha;
	GLint pos_attrib;
	GLint size;
	GLint position;
	GLint radius;
	GLint discard_transparent;
};

struct stencil_mask_shader {
	GLuint program;
	GLint proj;
	GLint color;
	GLint pos_attrib;
	GLint half_size;
	GLint position;
	GLint radius;
};

struct box_shadow_shader {
	GLuint program;
	GLint proj;
	GLint color;
	GLint pos_attrib;
	GLint position;
	GLint size;
	GLint blur_sigma;
	GLint corner_radius;
};

struct blur_shader {
	GLuint program;
	GLint proj;
	GLint tex_proj;
	GLint tex;
	GLint pos_attrib;
	GLint radius;
	GLint halfpixel;
};

struct shaders {
	struct quad_shader quad;
	struct tex_shader tex_rgba;
	struct tex_shader tex_rgbx;
	struct tex_shader tex_ext;
	struct box_shadow_shader box_shadow;
	struct stencil_mask_shader stencil_mask;
	struct blur_shader blur1;
	struct blur_shader blur2;
};

bool link_shaders(struct fx_renderer *renderer);

#endif
