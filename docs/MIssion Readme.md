# National University of Singapore 
 The Lift 
 EG2310 ‐  Fundamentals of Systems Design 

*V1.0 | 9 Jan 2024 | Royston Shieh*

## Introduction
The overall mission for the team is to develop a system that can be efficiently operated by anyone. The system will comprise of a robot with attached sensors and mechanisms to find, aim and fire ping pong balls into a bucket. The bucket is hidden in a “Lift” which is called by the robot when the robot reaches the “Lift Lobby”. 
There are 2 lifts that will arrive once the robot calls the lift at the lobby. Each group will have exactly 25 minutes to set up the materials execute the mission. The mission is considered complete once the robot fires all 5 ping pong balls into the bucket.

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
  
During this time, the TA will read the user manual to be familiar with the functioning of the system and may ask for some clarifications from the team. 
When the team is ready, they have to stay at least one metre from the arena and tell the TA that they are ready to start the missions. After this, the team will not be authorized to teleoperate or perform any manual operations to the robot. 
Finally, the team will declare to start the mission. 

### 2. THE MISSION 
The mission will consist of 3 phases, a start zone, a randomized maze zone and the Lift Lobby. The robot is to leave the start zone to enter the maze zone. In the maze zone, the robot is to map out the maze and find the exit of the maze. The robot will then enter the lift lobby. 

At the lift lobby, there are 2 lift doors. The robot is to make an HTTP call to a web server. The Webserver will then reply with a "Success" and the ID of the door that will open. The lift door will remain open for 60 seconds. The server will not respond to HTTP calls during this 60 second. The robot can make another HTTP call after this 60 second to attempt to open a door. 
If a failure error is encountered, the robot can attempt to make another call until a "Success" is received.

The door is a simple hinge door without any automatic actuation. The robot must push the door to open the door. 

Once the robot enters the lift, the robot is to find the target bucket and fire 5 ping pong balls into the bucket. The mission timing will end once the ping pong balls have been fired.

The TA may catch and power off the robot if necessary to prevent any damage or contact with the arena walls, the robot or any other elements of the maze. In this case, the current mission attempt will end and the team will receive a penalty applied to the overall score. 

The team may declare an official stop and re-attempt the mission for multiple tries within the time limit. 
During the missions, the TA will constantly fill the scoring form (in appendix 1, one for each mission). When he is finishes filling in the form after each mission, the team will have two possibilities:

-  The team agrees with the final score and signs the form. 
-  The team disagrees with the final score or want to do a re‐attempt to obtain a better score. If so, the team will have access to the arena to adjust the robot, dispenser and make modifications to the software. The team must inform the TA if there they make any major changes. When the members are ready and leave the arena, the team will declare a fresh start to the mission. The team can have as many attempts as they want for each mission.

### 3. End Phase
At the end of the 25 minutes, the current mission will stop immediately. The TA will stop filling in the Scoring Form and calculate the score for that attempt. This score will be automatically validated for this mission. 
The team must remove all their material from the arena before the end of this 25 minutes. During this time, the TA will calculate the final score for the team and share it with them. Any time-overrun will result in demerit points for the overall attempt.

## THE USER MANUAL 
The teams are to submit a user manual of not more than 5 pages for inspection before the mission is allowed to start. More information on the user manual will be discussed in G2. The user manual must include all the information necessary to help the TA to operate the robot and the map makers. The TA will quickly read the manual during the Setup Period and may read it during the mission if he thinks it is relevant.

## Scoring
Scoring is spilt into mission achievement based scoring, and time based competative scoring. 

### Mission Achievement Based scoring
For each mission, teams can score up to 100 points. Refer to the Scoring Form (Appendix 1). 
After all teams have completed the missions, they will be ranked based on the time required to setup the material and finish the missions. 
The final score will be the best score of the multiple attempts (i.e., points from each mission and points from the time ranking). 

### Time based competative scoring
Teams will be timed based on
- Time taken to deposit ping pong ball into the bucket. Timing will be taken once the first ping pong ball lands and remain in the bucket.
- Map closure. Timing will be taken once TA Verify full map closure.

Example 1.
The team starts the mission and takes 7 minutes to reach the bucket and successfully deposit the first ping pong ball into the bucket. The robot then re-enters the maze to map out the maze. Full map closure is achieved at the 12 minute mark.
- Mission time = 7 minute
- Map closure time = 12 minute

Example 2. 
The team starts the mission and takes 7 minutes to develop a complete map of the maze. The robot then enters the lift to deposit ping pong balls into the bucket. First successful ping pong ball deposit is achieved at the 12 minute mark.
- Mission time = 12 minute
- Map closure time = 7 minute

No timing is recorded if milestones are not achieved.  

# ROBOT REQUIREMENTS 

You are free to experiment and test any system that can complete the mission.

## The Robot
The robot platform must be a Turtlebot 3 Burger. No other requirement for the robot. 

## The Markers
The team is allowed to place temporary markers or beacons in the map to help the robot complete the mission. These markers must be installed and removed within the 25-minute time that the team have for the mission. There is no additional time given for removal of map markers. All markers must not leave a mark/stain/damage on any map element. 



--End--





