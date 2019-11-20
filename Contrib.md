
 # DEVELOPER DOCUMENTATION
 ------------------------------

 ## General directions
  **0. Get Connected**
  In the #general channel on the [Pollex Slack](sistemasopensource.slack.com), you can ask questions or discuss things related to Pollex development. 

  **1. Decide what you'd like to work on**
  Whether it's a feature or a bug fix, you'll need to know exactly how you want to improve Pollex.

  - You can choose an [existing issue](https://github.com/flossschool/pollex/issues);
  - There are some important issues on [milestones](https://github.com/flossschool/pollex/milestones);
  - If you've have something specific in mind and there's no existing issue for it, you can open it for community discussion.

  **2. Build your own copy of Pollex**
  In order to try out the changes you make, you'll want a local copy of Pollex's source code that you build yourself.

  - Decide which branch you'll work. Initially you can choose "work" branch;
  - Compile your working branch

  **3. Implement your improvement**
  Finally, get to work!

  - Your changes should follow the Pollex coding conventions:
    - This includes writing a good comments for parts of your code that may be hard for others to understand;
    - Follow the [PEP 8 - Style Guide for Python Code](https://www.python.org/dev/peps/pep-0008/) 
  - Test your code!

  **4. Create a pull request ("PR") and await review**
  Once your changes work on your local copy, it's time to share them.

   - [Create a PR](https://github.com/flossschool/pollex/compare);
   - Select as base "master" and as compare your branch ("work");
  
  **5. Celebrate!**
  Actually, you might get a few comments about things you have to change first. Even so, you've come a long way, so give yourself a pat on the back! If you are an SOS student, maybe you can be approved in class. 

 ## 2) Development environment
  **NEED DETAILED TIPS**
  - The best way to contribute for Pollex is using the [Docker](https://www.docker.com/) container, so all you'll need to develop are already installed.
    - First download the dockerfile in (where?);
    - Create the image: "docker build -t dockerfile";
    - Run the image: "docker run docker_image";
  - You can choose also the [cmake](https://cmake.org/) installation:
    - First download the repository;
    - Move to source directory (?) and enter "make" on terminal;
  

 ## 3) Repository policy
  This repository uses GNU GENERAL PUBLIC LICENSE.
  Everyone are welcome. Don't behave like Linus Torvalds, respect everyone who spends their time transforming this idea into a real project.

  

 

