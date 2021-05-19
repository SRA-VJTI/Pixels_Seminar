# TABLE OF CONTENTS
- [TABLE OF CONTENTS](#table-of-contents)
- [Version Control in git](#version-control-in-git)
- [Remotes and Local Repositories](#remote-repositories)
  - [Local Remotes](#adding-your-local-repository-as-a-remote)
  - [Fetching from and Pushing to Remotes](#fetching-and-pushing)
- [Three States of a Git file](#states-of-a-git-file)
- [Undoing commits](#undoing-commits)
- [Git Branching](#git-branching)



# Version Control in Git

* 'Version Control' basically logs changes made to a set of files, and provides the added functionality of reverting back to previous versions if need be
* Git is a 'Distributed Version Control System' (DVCS)
* Multiple 'clients' check out files from this central server
* Since git is a DVCS, the clients don't just check out the latest versions of these files, but alongwith it the entire commit history
* You can verify this by cloning this repository itself, and checking the commit history using the **git log** command
```
  git clone https://github.com/SRA-VJTI/Intro_to_CV.git
  git log -p -2 
```
**git log -p -2** shows the latest 2 modifications to the repository
You should see an output similar to this
<p align="center">
  <img src="./assets/git_log.JPG" width="500"/>
</p>

* This has the added advantage of restoring files from one of the client repositories, if any server faces file mishandling.






# Remote Repositories

* A remote repository is a version of your Git Directory on your local machine
* Multiple clients can have remote repositories of the same Git Directory
* When you **git clone** a repository, by default your established remote is **origin**
* You can verify this by running the following commands
```
  git clone https://github.com/SRA-VJTI/Intro_to_CV.git
  git remote -v
```
<p align="center">
  <img src="./assets/remote_v.JPG" width="500"/>
</p


# Adding your local repository as a remote

* You can add a seperate remote of your local repository
* In doing so, your local files will not be visible on the main Git Directory
* But collaborators can access your local files by using your remote by running the **git fetch** command

Adding your own remote named 'new_remote' :
```
  git clone https://github.com/SRA-VJTI/Intro_to_CV.git
  git remote -v
  git remote add new_remote https://github.com/SRA-VJTI/Intro_to_CV.git
```
Fetching from the new remote:
```
 git fetch new_remote
 
```
<p align="center">
  <img src="./assets/adding_remote.JPG" width="500"/>
</p


# Adding your local repository as a remote

* To get data from any remote repository, for example a remote named 'my_remote', just run
```
 git fetch my_remote
```
---------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------
**Using git fetch on a cloned repository**

* By default, the git clone command will set your remote as the origin, as we have seen above
* So to get modified data from the origin after cloning, you can just run 'git fetch origin'
**Note : This will not make any changes to your existing files on your local repository**

---------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------

* If you want to publish your project uptil now to your git server, you can run the 'git push' command as follows
```
 git push <remote> <branch>
```

Example : If you want to push changes to the 'main' branch of your 'origin' remote, the command will be
```
 git push origin main
```


# States of a Git file

* Git being a version control system needs a way to **track all the changes made to the files in your local repository**
* This is significant when you want your collaborators to be able to view and access the local changes you make to the files.
* Thus, each file in your git repository can be either **tracked** or **untracked**
* To understand this, let's go through the basic Git workflow for a file:
1. **Modified** : Your file gets modified in your **working tree**. At this stage, your changed file remains **untracked**, and other collaborators will **not** be able to access the changes you made from the server.
<p align="center">
  <img src="./assets/untracked_git.JPG" width="500"/>
</p>
2. **Staged** : Only the changes in the files that you select using the **git add** command will be recorded in the next version of your repository. These files reside in the **staging area**. Your changed file is now **tracked**. You can verify this by re-running the **git status** command
<p align="center">
  <img src="./assets/untracked_git.JPG" width="500"/>
</p>

If you modify your file again after it has been staged with git add, Git with list it as an untracked file again. You can verify this by running the git status command again.

<p align="center">
  <img src="./assets/staged_then_untracked_git.JPG" width="500"/>
</p>

3. **Committed** : Once you perform the **git commit** command, the files you have in your staging area get stored as a new version in your **Git directory**

<p align="center">
  <img src="./assets/commit_git.JPG" width="500"/>
</p>



![](https://git-scm.com/book/en/v2/images/areas.png)





## Undoing commits

* If you want to make certain changes to your last commit and not have it appear as a seperate commit in your version history, you can use the **git commit --amend**
```
  git commit -m 'Changed files'
  git rm file_to_be_removed
  git commit --amend
```
<p align="center">
  <img src="./assets/commit_amend_git.JPG" width="500"/>
</p>


