#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t robot_status;
    robot_status.direction = direction;
    robot_status.position.x = x;
    robot_status.position.y = y;

    return robot_status;
}


void robot_move(robot_status_t *robot, const char *commands)
{
    for (int i = 0; commands[i] != '\0'; i++) {
        if (commands[i] == 'A') {
            if (robot->direction == DIRECTION_NORTH) 
                robot->position.y++;
            else if (robot->direction == DIRECTION_SOUTH) 
                robot->position.y--;
            else if (robot->direction == DIRECTION_WEST) 
                robot->position.x--;
            else if (robot->direction == DIRECTION_EAST) 
                robot->position.x++;
        }
        else if (commands[i] == 'R') {
            robot->direction = (robot->direction + 1) % 4;
        }
        else if (commands[i] == 'L') {
            robot->direction = (robot->direction + 3) % 4;
       }
    }
}
