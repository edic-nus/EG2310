# National University of Singapore 
 Search & Rescue of An Earthquake Disaster Zone
 CDE2310 ‐  Fundamentals of Systems Design 

*V1.0 | 6 Jan 2025 | Nicholas Chew*

## Introduction
The overall mission for the team is to develop a system that can be efficiently operated by anyone. The system will comprise an autonomous navigation robot (turtlebot) with attached sensors and mechanisms to find heat signals (infra-red) in an unknown area and fire flares (ping pong balls) vertically to signal search and rescue (S&R) teams to attend to survivors immediately. Heat signals are heat sources (infra-led lamp) behind the maze walls (acrylic sheets) and upon signal detection will instruct robot to stop immediately and trigger flare firing sequence. There are 2 "survivor" zones with 2 distinct heat signals.

Due to the mission theme, line following navigation is forbidden henceforth. Each group will have exactly 25 minutes to set up the materials execute the mission. The mission is considered complete once the robot fires all 4 ping pong balls (2 flare attempts for each zone) vertically achieving 2m elevation in order to clear all vertical obstructions for successful signaling (a 2m target will be placed where the heat signatures are).

There will be a 3rd survivor zone featuring a ramp but it is not mission critical. Scaling a ramp using a 2-D lidar on a turtlebot is extremely challenging but bonus points will be awarded for successful completion of this added mission objective. Confident groups can attempt this after satisfying the basic objectives. The ramp will always be in a known area of the search and rescue disaster zone (e.g. 1 of the top 4 corners of maze) and ramp elevation specs (e.g. height, ramp travel distance, etc.) will also be made known by week 7.

## The Steps
The final examination will be divided into 3 periods, a Setup Period to install the equipment, the mission and an end Phase to clean the arena. The team will have exactly 25 minutes to set up the materials, complete the examination and leave the area. 

###	1. THE SETUP PERIOD 
During the Setup Period, the team is to: 
- place marker or beacons in the maze 
- place the robot at the start zone 
- set up the computer on the table near the start zone 
- start all the software
- Ensure ping pong balls are loaded into the robot
- Any other activity, setup, calibration or tests required for completion of the mission
  
During this time, the TA will read the group's user manual to be familiar with the functioning of the system and may ask for some clarifications from the team. 
When the team is ready, they have to stay at least one metre from the arena and tell the TA that they are ready to start the missions. After this, the team will not be authorized to teleoperate or perform any manual operations to the robot. 

Finally, the team will declare to start the mission and also express to examiner and TAs whether to attempt the bonus objective.

### 2. THE MISSION 
The mission will consist of 4 phases, a start zone, a randomized maze zone, the survivor zone, and the optional bonus ramp zone. The robot is to leave the start zone to enter the maze zone. In the maze zone, the robot is to map out the maze and find the exit of the maze. The robot will then enter the survivor zone.

At the survivor zone, The robot is to pause directly facing the heat signature and commence the flare signaling sequence. If a failure error is encountered, the robot can attempt to make another firing sequence to hit the vertical target. Regardless of success, the robot will need to re-enter the maze zone to search for the next survivor zone.

Once the robot enters 2nd survivor zone, it will repeat the flare signaling process. The mission timing will officially end once the ping pong balls have been fired.

Depending on the team's mission direction, they may continue to execute the bonus objectives and navigate to the ramp zone. Any errors from this point henceforth, will not affect final scoring. Bonus objectives will also not be timed and bonus points will be awarded on the 3 scenarios: i) arriving at ramp zone ii) arriving at ramp zone and successful ramp scaling of ramp & iii) (i) + (ii) ramp scaling with successful flare signaling.

The TA may catch and power off the robot if necessary to prevent any damage or contact with the arena walls, the robot or any other elements of the maze. In this case, the current mission attempt will end and the team will receive a penalty applied to the overall score. 

The team may declare an official stop and re-attempt the mission for multiple tries within the time limit. Grps are strongly advised to fulfill basic objectives first and then attempt bonus objectives.

During the missions, the TA will constantly fill the scoring form (in appendix 1, one for each mission). When he/she finishes filling in the form after each mission, the team will have two possibilities:

-  The team agrees with the final score and signs the form. 
-  The team disagrees with the final score or want to do a re‐attempt to obtain a better score. If so, the team will have access to the arena to adjust the robot, markers and make modifications to the software. The team must inform the TA if there they make any major changes. When the members are ready and leave the arena, the team will declare a fresh start to the mission. The team can have as many attempts as they want for each mission as long as it is within the stipulated time limit.

### 3. End Phase
At the end of the 25 minutes, the current mission will stop immediately. The TA will stop filling in the Scoring Form and calculate the score for that attempt. This score will be automatically validated for this mission. 
The team must remove all their material from the arena before the end of this 25 minutes. During this time, the TA will calculate the final score for the team and share it with them. Any time-overrun will result in demerit points for the overall attempt.

## THE USER MANUAL 
The teams are to submit a user manual of not more than 5 pages for inspection before the mission is allowed to start. More information on the user manual will be discussed in G2. The user manual must include all the information necessary to help the TA to operate the robot and the map makers. The TA will quickly read the manual during the Setup Period and may read it during the mission if he thinks it is relevant.

## Scoring
Scoring is spilt into mission achievement based scoring, and time based competative scoring with a bonus component.

### Mission Achievement Based scoring
For each mission, teams can score up to 100 points with an additional 20 point bonus component (it is theoretically possible to get over 100 points). Refer to the Scoring Form (Appendix 1). 
After all teams have completed the missions, they will be ranked based on the time required to setup the material and finish the missions. 
The final score will be the best score of the multiple attempts (i.e., points from each mission and points from the time ranking) and bonus points.

### Time based competative scoring
Teams will be timed based on
- Time taken to hit vertical targets in each survivor zone. Timing will be taken once the first ping pong ball hits the 2m target.
- Map closure. Timing will be taken once TA Verify full map closure.

Example 1.
The team starts the mission and takes 7 minutes to reach the first survivor zone. The robot then re-enters the maze to map out the maze and 2nd survivor zone. Full map closure is achieved at the 12 minute mark.
- Mission time = 7 minute
- Map closure time = 12 minute

Example 2. 
The team starts the mission and takes 7 minutes to develop a complete map of the maze. The robot then enters the first survivor zone and first flare signaling is achieved at the 12 minute mark.
- Mission time = 12 minute
- Map closure time = 7 minute

No timing is recorded if milestones are not achieved.  

# ROBOT REQUIREMENTS 

You are free to experiment and test any system or path planning algorithms that can complete the mission.

## The Robot
The robot platform must be a Turtlebot 3 Burger. No other requirement for the robot. 

## The Markers
The team is allowed to place temporary markers or beacons in the map to help the robot complete the mission. These markers must be installed and removed within the 25-minute time that the team have for the mission. There is no additional time given for removal of map markers. All markers must not leave a mark/stain/damage on any map element. 


## ADDENDUM 1
Mission Rules Update

1. All members of the team, except for ONE designated operator must be behind the checking table for the mission time to start.

2. The mission time will start if 
a. The robot operator request that we start the time
b. The robot moves off the start line

3. The mission will end if any part of the system or terminal is interrupted by anyone for any reason. This include TA catching the bot to prevent damage to the bot or the maze. The team can then bring the robot back to the start line to restart the mission

4. You must screen record the RVIZ map for submission regardless if you are aiming for map completion. 

5. NEW - Forfeit competitive scoring

At the 14th minute mark (6 minute before the end of booking slot), the team can now choose to forfeit on the competitive scoring component. You can then start the mission from the 1st survivor zone, and score partial points for 

- Robot successfully detects heat signature 
- Robot successfully orientates to face the heat signature frontally 
- Robot stops and fires flare successfully
- 1 of 2 Ping Pong ball successfully hits 2m target.

An updated scoring sheet with this "white flag" scenario will be uploaded on github.

6. NEW - Line following for maze solving not accepted

100% Line-following fully closed Rviz map will not be accepted for competitive scoring. This decision is made as these map are considered human-solved and not autonomously developed. This apply to any other human-solved solution for "Mapping completion time" competitive scoring.
It is acceptable for the robot to update the map while following a "marker" to the survivor zone or during the mission. The system must then autonomously seek for the unmapped area and complete the map. 

--End--





