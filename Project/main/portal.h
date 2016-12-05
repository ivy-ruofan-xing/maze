#ifndef PORTAL_H_INCLUDED
#define PORTAL_H_INCLUDED

int portalPos[2][2] = {{0, 0}, {0, 0}};

void updatePortalPosition();  //new positions of the portals for when it needs to be moved and redrawn

int checkIfOnPortal();  //move the ball to the next portal if it goes through


#endif
