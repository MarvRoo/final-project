# Murder Mystery Text-Based Role-Playing Game (RPG)
 
 > Authors: [Ashley Lopez](https://github.com/alope808) [Sarah Nguy](https://github.com/2803sn) [Marvely Rodriguez-Calva](https://github.com/MarvRoo) [Naomi Menard](https://github.com/naomimenard)

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

<img width="719" alt="Image" src="https://github.com/user-attachments/assets/a0e0a9d5-11e1-48cb-adca-3601d41f0956" />

<img width="374" alt="Image" src="https://github.com/user-attachments/assets/e70ffb8d-db70-4a19-8ef2-c74e83b74cf5" />

<img width="630" alt="Image" src="https://github.com/user-attachments/assets/cc4cc4bc-a900-4e8e-9d6e-ced7fa8f3a46" />

<img width="1111" alt="Image" src="https://github.com/user-attachments/assets/06a882f3-d3d0-4b07-a163-4d7a74f05a73" />


## Class Diagram
> Old:
![Murder Mystery UML Class diagram](https://github.com/user-attachments/assets/c468d84c-2d05-4538-985b-521f732c746c)
 
 > ## Phase III
> Updated Class Diagram:
![Murder Mystery UML Class diagram (5)](https://github.com/user-attachments/assets/6d9d7e03-ccda-4f75-acb3-50ed5a5151c6)
> Applied Solid Principles Class Diagram:
![Murder Mystery UML Class diagram(Improved Further) (4)](https://github.com/user-attachments/assets/6d8444e6-a8df-420f-8540-88c933025ed5)
>

> 1. We applied the SRP (Single responsibility principle) to the Person class. We applied this by dividing it further into an Autopsy class. This change helped reduce the complexity in the person class and allowed us to > simplify our implementation to be more efficient.

>
> 2. In order to follow the SRP and OCP from the SOLID design principles, we decided to separate the original Dialogue class, which was handling both character dialogue and player choices. We chose to split this into creating an abstract base class (DialogueUnit), and split the functionality into two subclasses, Dialogue and Choice, handling their respective actions. Each class is now clear and no longer cluttered, following the SRP and if new dialogue behaviors are ever to be added, it won’t alter existing code (won’t violate OCP).
>

>
>3. In order to incorporate DIP principle, we decided it would be best to make dialogue a subclass and create another subclass called choice that varies from regular dialogue under the polymorphism class DialogueUnit. In order to store their deep copies in the same vector pointer we made the class DialogueUnit is a base that allows high level components like gameloop and printer to work and access different dialogue types without having to know the concrete sub-classes. It helped us right better code by avoiding object slicing.
>

>
>4. The SRP principle was applied to the Dialogue Class which created the gameloader class and ending class. 
Before, the dialogue class had the responsibility to load the dialogue and endings, locations , and clues.
The gameloader class now handles the responsibilities of loading the dialogue, locations, and clues, while the 
ending class has the responsibility of generating different endings based on the point system. The dialogue
class now handles the responsibility of setting the dialogue and is able to print out the dialogue when
an object calls the print function in the dialogue class.  This change helps us reduce the number of code for writing the responsibilities for the dialogue class as we create the ending and gameloader classes to handle the other 
responsibilities the dialogue class was responsible for before.
 
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
 
