#ifndef SCENES_GEN_H
#define SCENES_GEN_H

GLuint pass_textures[1], pass_framebuffers[1];

void create_render_framebuffers()
{
    glGenFramebuffers(1, pass_framebuffers);
    glGenTextures(1, pass_textures);
    glBindTexture(GL_TEXTURE_2D, pass_textures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void setup_scene_0_rendergraph()
{
    glBindFramebuffer(GL_FRAMEBUFFER, pass_framebuffers[0]);
    glBindTexture(GL_TEXTURE_2D, pass_textures[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, pass_textures[0], 0);
    glDrawBuffer(GL_COLOR_ATTACHMENT0);
    glBindFramebuffer(GL_FRAMEBUFFER, pass_framebuffers[0]);
    glBindTexture(GL_TEXTURE_2D, pass_textures[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, pass_textures[0], 0);
    glDrawBuffer(GL_COLOR_ATTACHMENT0);
}

#define t_0 (0.0)
const double start_times[] = {
    t_0
};
const char *scene_names[] = {
    "Logo 210"
};
const unsigned int nscenes = ARRAYSIZE(start_times);
#endif
