#ifndef DEBAG_H
#define DEBAG_H

#define DEBUG_RUN

#ifdef DEBUG_RUN
class StageManager;
void DebugDrawHitRect(StageManager *manager);
#endif

#endif