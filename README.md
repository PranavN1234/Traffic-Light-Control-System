# Traffic-Light-Control-System
Implement a traffic light control system to reduce congestion, improve traffic flow, and allow manual intervention when necessary

Lab Objective: To apply knowledge learned in lab 2 to real-world application. This project is
designed to challenge students to implement a state machine using buttons and LEDs. The
system must be able to automatically cycle through the traffic light sequence and allow for
manual intervention if necessary. Students must demonstrate their understanding of state
machines, as well as their ability to design and implement a system using input and output
devices.
Title: Design a Traffic Light Control System
Problem: You have been assigned to California’s Division of Traffic Operations. A traffic
intersection has a problem with traffic congestion during peak hours. The traffic lights are
poorly timed, causing long wait times and traffic jams. Your task is to implement a traffic light
control system that will reduce the wait time for drivers and improve traffic flow. The traffic
light system consists of two intersections, North-South and East-West.
The traffic light control system will operate in the following way:

• Both intersections will initially be red and the pedestrian light is red.
• After 10 seconds, the North-South light turns green, and the East-West light is red.
• After 20 seconds, the North-South light turns yellow for 3 seconds before turning red.
• After 5 seconds of red light at the North-South light, the East-West light turns green,
and the North-South light remains red.
• After 20 seconds, the East-West light turns yellow for 3 seconds before turning red.
• After 5 seconds of red light, the system returns to the initial state of both lights being
red.
The system should be designed to allow for manual intervention if necessary. A push button at
each intersection can be used to trigger a pedestrian crossing mode. When the button is
pressed, the current green light should change to flashing yellow for 10 seconds, then switch to
red to allow pedestrians to cross for 15 secs. At this state, the other light should continue to
remain red, and the pedestrian light turns green. Once the pedestrian crossing mode is
complete, the system should return to the previous state.

FULL QUESTION PDF ATTACHED IN THE REPO
