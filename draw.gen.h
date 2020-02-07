#ifndef DRAW_GEN_H
#define DRAW_GEN_H
if(t < t_scene2)
{
    glUseProgram(shader_program_gfx_scene1.handle);
    glUniform1f(shader_uniform_gfx_scene1_iTime, t - t_scene1);
    glUniform2f(shader_uniform_gfx_scene1_iResolution, w, h);
#ifdef MIDI
    glUniform1f(shader_uniform_gfx_scene1_iFader0, fader0);
    glUniform1f(shader_uniform_gfx_scene1_iFader1, fader1);
    glUniform1f(shader_uniform_gfx_scene1_iFader2, fader2);
    glUniform1f(shader_uniform_gfx_scene1_iFader3, fader3);
    glUniform1f(shader_uniform_gfx_scene1_iFader4, fader4);
    glUniform1f(shader_uniform_gfx_scene1_iFader5, fader5);
    glUniform1f(shader_uniform_gfx_scene1_iFader6, fader6);
    glUniform1f(shader_uniform_gfx_scene1_iFader7, fader7);
#endif
}
else {
    glUseProgram(shader_program_gfx_scene2.handle);
    glUniform1f(shader_uniform_gfx_scene2_iTime, t - t_scene2);
    glUniform2f(shader_uniform_gfx_scene2_iResolution, w, h);
#ifdef MIDI
    glUniform1f(shader_uniform_gfx_scene2_iFader0, fader0);
    glUniform1f(shader_uniform_gfx_scene2_iFader1, fader1);
    glUniform1f(shader_uniform_gfx_scene2_iFader2, fader2);
    glUniform1f(shader_uniform_gfx_scene2_iFader3, fader3);
    glUniform1f(shader_uniform_gfx_scene2_iFader4, fader4);
    glUniform1f(shader_uniform_gfx_scene2_iFader5, fader5);
    glUniform1f(shader_uniform_gfx_scene2_iFader6, fader6);
    glUniform1f(shader_uniform_gfx_scene2_iFader7, fader7);
#endif
}
#endif
