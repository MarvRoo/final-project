# Murder Mystery Text-Based Role-Playing Game (RPG)
 
 > Authors: [Ashley Lopez](https://github.com/alope808) [Sarah Nguy](https://github.com/2803sn) [Marvely Rodriguez-Calva](https://github.com/MarvRoo) [Naomi Menard](https://github.com/naomimenard)

 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list and start thinking about the features you will implement. If you want to propose your own original idea, you will have to contact your instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings.

 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo.

## Project Description
 > **We choose the text-based role-playing game for our project because we wanted to gain hands on experience of what’s it’s like to create a game and to understand the complexities that comes along with it. Making a PRG project will allow us to enhance our current understanding of C++ concepts such as polymorphism, inheritance, and classes and how to apply it to a real-life programming situation. We also like that it’s a throwback to a horror style game that became popular a couple of years ago in 2015-2017. So it would be fun and interesting to create a story of our own.**
 > **We plan to complete the project with C++. We will work in VS Studio Code and use tools like the GDB debugger to aid in the process. For communication and smooth efficiency in implementing features, we will rely on GitHub for pull requests and utilize the project board to aid in task management.**  
> **Inputs of our project will include: inputing a letter (ex. a,b,c,d)  to  select a specific hint/clue (a character's testimony or an item used by the characters), asking for player's input to select who they think the murderer is, and inputing how many hearts to see how many chances they have left before they loose the game from not selecting the correct murderer. Outputs of our project will include: outputing the character's testimonies or the item's clue, outputing if the player was right or wrong from guessing who the murderer is, the number of chances they have left before they loose, and outputing who the murderer is if the player wasn't able to guess correctly.**

> **Features include saved inputs to save game progress when a player dies so they don’t restart the game. We’ll create a concise, engaging narrative with a clear goal or questline. Along with it we hope to be able to create a simple interface messenger look still remaining text based to immerse the user better. There will be characters created that will need to have their own dialogue. We will be using multiple classes and functions to help bring this to life.**
 

 > ## Phase II
> 
### Navigation Diagram
![Murder Mystery Navigation Diagram](https://github.com/user-attachments/assets/2a1255e9-ff58-4eb1-b2ad-f77d90cef110)



### Screen Layouts
> The layout of the project will be text based where the user will be expected to give input, expect output (from character testimonials for example), and recieve character insights to help solve the game via dialogue on the screen. Because it is text based, players are able to interact with this game using the linux or VS Code terminal. During the start of each day, the screen will output some context of the main occurrence that has happened. Players are able to search for clues in the locations given by inputing 'c'  and move in different locations by inputing the specific location. As the player moves to a certain location, the screen will then output where the player is currently is. Players are also given the option to interview potential suspects by being prompted with a question on the screen if they want to interview them. In addition, users are also able conduct analysis about who the suspect could be after being prompted with the character's dialogue when selecting the choice of speaking to them or when choosing who they think the suspect is. At the end of each day, players will be given a recap of all the clues they have garnered and will be expected to input a character to interview the next day. 

## Class Diagram
![Murder Mystery UML Class diagram](https://github.com/user-attachments/assets/c468d84c-2d05-4538-985b-521f732c746c)


 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
