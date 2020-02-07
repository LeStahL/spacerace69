#ifndef SCENES_GEN_H
#define SCENES_GEN_H

#define t_scene1 (0.0)
#define t_scene2 (20.0)
const double start_times[] = {
t_scene1,
t_scene2
};
const char *scene_names[] = {
"Scene 1",
"Scene 2"
};
const unsigned int nscenes = ARRAYSIZE(start_times);
// We need these two arrays to always have the same size - the following line will cause a compiler error if this is ever not the case
_STATIC_ASSERT(ARRAYSIZE(start_times) == ARRAYSIZE(scene_names));
#endif