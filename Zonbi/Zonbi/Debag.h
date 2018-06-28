#ifndef DEBAG_H
#define DEBAG_H


#ifdef DEBUG_RUN
class StageManager;
class PlayerZombie;
void DebugDrawHitRect(StageManager *manager);
void DebugPlayerHitRect(PlayerZombie *player);
#endif

#endif