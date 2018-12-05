## ToDoList:
Detached HEAD state.   

 



 

 

 



 

 

## Other tools:
- git-completion.bash . -- 
- git-prompt.sh -- This script allows you to see repository status in your prompt:      export PS1='[\u@\h \W$(__git_ps1 " (%s)")]\$ '

 

## Rules:
- fetch before you work.
- fetch before you push.
- fetch often.

 

 

 

 

## Daily work flow example:
- git checkout <mastrer>    // switch branch to <master>
- git fetch     // sync remote to local repository's origin/<master>)
- git log -p <master>..<origin>/<master>　　// check details diff between local working banch and local repository sync-ed branch, -p option means patch
- git merge  <origin>/<master>    // merge local repository <origin>/<master> to working <master>
- [create new branch: git checkout -b <new branch name> ]      //create new branch
- [check out existing branch: git checkout -b <existing branch name> <origin>/<existing branch name>]　　// check out existing brach
- git log 　　// check change logs
- git show XXXXX / git show HEAD~<n>　　// check the detail of one commit change
...make changes...
- git add <change file>     // add changes to stage
- git commit -m "change commit messages"     // commit changes from local stage to local repository.
- git fetch    // before push, do the fetch again.
- git push -u <origin> <master>　　// push the local repository changes to remote repository, -u option make the branch as a tracking branch.
 

 

## HEAD
- pointer to "tip" of current branch in repository (not stage & working dir).
- the last state of repository, what was last checked out.
- points to parent of next commit(where writing commits take place).

 

 

## other useful commands:
- git branch --merged　　// list all the branches which merged into current branch.
- git branch -r --merged　　// for remote branch
- git branch --no-merged　　// list all the branches which haven't been merged into current branch.
- git branch -d <branch name>　　// delete another branch whose name is <branch name>, current working branch should be different from <branch name>
- git branch -D <branch name>　　// force delete branch <branch name>
- git push <origin> :<branch name>　　// delete remote branch, push's full patter is git
- push <origin> <local branch name>:<branch name>, here <local branch name> is null, means push blank to remote.
- git push --delete <origin> <branch name> 　　// delete remote branch from Git version 1.7,0+
- git push --d <origin> <branch name> 　　// delete remote branch from Git version 2.8,0+

 

## GIT diff
![GIT diff](../resource/images/GIT/git_diff.jpg)

 

## Branch:
- Branch on the remote repository (e.g. master)   -- in remote repository
- Local snapshot of the remote branch (e.g. origin/master)  -- in local repositry
- Local working branch, tracking the remote branch (e.g. master in local working)  --  local working
 

## Tag:
### Add tag
- light weight tag: git tag <tag name> <SHA>
- annotated tag: git tag -a <tag name> -m <"message"> <SHA>
### List tag
- git tag
- git tag --list
- git tag -l
- git tag -l <"regex">
- git show <tag name>
- git diff <tag1>..<tag2>
### Delete tag
- git tag --delete <tag name>
- git tag -d <tag name>
### Push tag
- git push does not ransfer tags, tag must be explictly transfered.
- git fetch automaticlly retrieves shared tags.
- push singal tag: git push <origin> <tag name> ; push all tags: git push <origin> --tags
- fetch only tags: git fetch --tags ; fetch commit and tags: git fetch
- delete remote tag: git push <origin> :<tag name> , or git push tag --delete <origin> <tag name>, or git push tag -d <origin> <tag name>
- Check out tag: git checkout -b <new banch name> <tag name> or git checkout <tag name> 

 

### Interactive staging: git add -i
- patch mode: allow staging portions of a changed file: 
- git add -p or git add --patch
- git stash -p
- git reset -p  
- git checkout -p 
- git commit -p 

- "hunk": an area where two files are differ
- hunks can be staged, skipped, or split into smaller hunks.
- split a hunk:  in interactive mode, select path mode, then select option: s
- edit a hunk:   in interactive mode, select path mode, then select option: e

 

### Chery picking
- Apply(grab) the changes from one or more existing commits.
- Each existing commit is recorded as new commit on the current branch, and those new commits will have different SHAs.
- git cherry-pick <SHA no>　　// grab one commit
- git cherry-pick <SHA no>..<SHA no>　　// grab range of commits
- Cannot cherry pick a merge commit.
- user --edit or -e to edit the commit message.

### Resolve the cherry-pick conflicts
- after resolve the conflicts, 
- git cherry-pick --continue 　　//continue
- git cherry-pick --abort　　// abort

 
## diff patches
### Create diff patches
share changes via files; useful when changes are not ready for public branch; useful when collabrators do not share a remote; dicuss, review, approval process.  

- git diff <from-commit> <to-commit> > <output.diff>　　//create diff patches

### Apply diff patches
- git apply <output.diff>　　//apply diff patches  
A patch can only apply if your working directory is in a state that allows it to work.

 

## Format patch 
- git format-patch <range from SHA>..<range to SHA>　--stdout > <patchname.patch>　// range of commits, and output to a single file

- git format-patch -1 <SHA>　　// single commit
- git format-patch <branch name> -o <output dir>　　// create a formated patch according to the branch name and output to a dir

### Apply format path
- git am <patch file.patch>　　// apply single mailbox formatted patch 
- git am <dir/*.patch>　　//apply all patch under a dir

 
- git am is diff from git apply, git am leaves nothing in working dir, while git apply leaves changes in working dir, you have to manually commit them.

 

## Rebase commits
- Take commits from a branch and replay them at the end of the another branch.  
- Useful to integrate recent commits without merging.
- Maintains a cleaner, more linear project history.
- Ensure topic branch commits apply cleanly.

- git rebase <rebase new base branch name> <the branch name you want to move>  
e.g.  
git rebase master new_feature　　// rebase new_feature branch to the tip of the master branch  
  
git rebase master　　// rebase current branch to the tip of the master branch  
  
 

## Golden rule of rebase:
- Thou shalt not rebase a public branch.

- rebase abandons existing, shared commits and create new, similar commits instead.
- collabrators would see the project history vanish.
- getting all the collabrators back in sync can be a nightmare.
 

## Merge V.S. Rebase
- Merge and Rebase are two ways to incoporate changes from one branch into another branch.
- Similar ends, but means are different.
### For merge:
- adds a merge commit.
- nondestractive.
- complete record of what happened and when.
- easy to undo. (hard reset)
- logs can become clusttered, non-linear.
### For rebase:
- no additional commit.
- destructive: SHA changes, commits are rewritten.
- no longer a complete record of what happened and when.
- tricky to undo.
- logs are cleaner, more linear.
### How to choose?
- merge: to allow commits to stand out or to be clearly grouped.  
merge to bring large topic branches back to master branch.  
- rebase to add minor commits in master to a topic branch.  
rebase to move commits from one branch to another.  
- merge anytime the topic branch is already public and being used by others.(Golend rule of rebasing).  

 

### Resolve rebase conflicts
- git pauses rebase before each conflicting commit.
- git rebase --continoue
- git rebase --skip
- git rebase --abort

### Rebase onto other branches
- git rebase --onto <new base> <upstream> <branch>  
e.g.   
git rebase --onto master ecommerence new_feature  

 

 

 

## useful for visualizing branches
git log --graph --oneline --all --decorate
 

## return commit where topic branch diverges
git merge-base <master> <new_feature>
 

 
