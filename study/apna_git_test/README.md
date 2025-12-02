# apna_git_test
>> 
>> # first we set the git global to my github 
>>     rajse@DESKTOP-0SIQMQ9 MINGW64 ~
>>     $ git config --global user.name "rajsekharsingh5242523"
>> 
>>     rajse@DESKTOP-0SIQMQ9 MINGW64 ~
>>     $ git config --global user.email "rajsekhar5242523.singh@gmail.com"
>> 
>>     rajse@DESKTOP-0SIQMQ9 MINGW64 ~
>>     $ git config --list
>>         diff.astextplain.textconv=astextplain
>>         filter.lfs.clean=git-lfs clean -- %f
>>         filter.lfs.smudge=git-lfs smudge -- %f
>>         filter.lfs.process=git-lfs filter-process
>>         filter.lfs.required=true
>>         http.sslbackend=schannel
>>         core.autocrlf=true
>>         core.fscache=true
>>         core.symlinks=false
>>         pull.rebase=false
>>         credential.helper=manager
>>         credential.https://dev.azure.com.usehttppath=true
>>         init.defaultbranch=master
>>         user.name=rajsekharsingh5242523
>>         user.email=rajsekhar5242523.singh@gmail.com
>> 
>>
>> # for cloning a repository
     git clone <git HTTPS>       #to bering file from git(online) to our looal computer code editor
         EX: git clone https://github.com/rajsekharsingh5242523/apna_git_test.git
    
     git --version  #to check if git downloaded properly

     cd  #change the directory in  the terminial
     
     ls  #to show files in the dictory
     
     ls -a   #to show hiddin files
    
     git status
>>
>> # it will show which branch you are
>>   if you did any changes then what is there status 
>>   if show :
>>     unmodified: no changes done
>>     modified and red : it was modifed and not taken any screenshort means not staged like don't saved the changes before run (took the the screenshort)
>>     Untracked files : new file that github does not know
>>
>>     staged : the file is save and runned(took the the screenshort) it does not reflect in the website of github
>>
>>     git add <file name>  # Add is like enganing and commmit is marrage sif do status we see it green
>>
>>     git commit -m "some message"
>>          still we can not see the file in the github and see the status
>>
>>
>> # in the status it show that  your branch is ahead of orgin  by 1 commits
>>     git push origin main      # to upload local content to website
>>
>> # to make a dictory from terminal
>>     mkdir <file name>
>>
>> # to make this local system into  github
>>     STEP1 : make a file
>>
>>     STEP2 : make the file into git file
>>         git init
>>         # to check see that in its hidden filr and .git is there or not
>>
>>     STEP3 : make a repo in git hub only dont clone
>>
>>     STEP4 : we are making a remote repo
>>         git remote add origin <your https>
>>     STEP5 : to verify which remote we are working
>>         git remote -v
>>     STEP6 : to check which  branch we are working
>>         git branch    --> * master
>>     STEP7 : to rename the branch to main here branch is like think a team has a developing group and testing group so the develper can just take the part of code  from the file and use it for them
>>         git branch -M main
>>     STEP8 : to push in github
>>         git push -u origin main     # here we use the -u flag so that if we are goint o wwork in this repo them not all time to write  origin main se just write git push     

# WHAT IS BRANCH
    think it like me main coder and i say john to add the feature of alerm then he will copy the main code and work on it and then i work with the real and latter we combine our both code

    Create a branch from terminal
        git checkout -b <name>  # here the green represent the current brach you are working
    Change between branch
        git checkout <name>    
    TO delect any branch 
        git branch -d <name>  #for delecting a brach we should not be in the deleting branch

    >>then push it to the branch 
        git push origin <name new branch>


# PULL request :it tell others about changes you've pushed to a branch in a repository on GitHub
    so the project  manager  will review your PULL REQUEST and thay can only do the accept it and merge to the main the branch

    1)from terminal 
        git merge <branch-name>
    2)from the github
        create a pull request and the admin will conform the request 

>> but in the main branch the in vs code it does not reflect in local

# PULL command : to fetch content from remote repo and update with locate repo
        git pull origin main    # for that you have to be in the main


# MERG CONFLICT
    SAY in two branch in the same line one code you add some thing and other same place you added somr thing else
    then we have resolve this  