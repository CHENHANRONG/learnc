Introduction to Git - Core Concepts (recommended prerequisite): https://youtu.be/uR6G2v_WsRA

Reference:
https://git-scm.com/book/en/v2

Commands Used:
git init - initialize a new repo in a directory
git config --global user.name "name"
git config --global user.email "email"
(--local option as well)
git status - see the state of files in working tree, staging area vs latest commit in git history
git add - move file(s) to the staging area
git log - view the git history / git commit graph
git diff - diff of working tree and staging area
git diff --cached - diff of staging area and latest commit
git rm - remove a file from the working tree and the staging area
git checkout -- filename - retrieve a file from the staging area into the working tree
git reset HEAD filename - retrieve a file from the latest commit into the staging area
git checkout (commit hash) filename - retrieve a file from a previous commit
git log =  git history
git log --all --decorate --oneline --graph = commit history graph
git branch (branch-name) = create a branch
git checkout (branch-name) = checkout a branch/move head pointer
git commit -a -m "commit message" = commit all modified and tracked files in on command (bypass separate 'git add' command)
git diff master..SDN = diff between 2 branches
git merge (branch-name) = merge branches (fast-forward and 3-way merges)
git branch --merged = see branches merged into the current branch
git branch -d (branch-name) = delete a branch, only if already merged
git branch -D (branch-name) = delete a branch, including if not already merged (exercise caution here)
git merge --abort = abort a merge during a merge conflict situation
git checkout (commit-hash) = checkout a commit directly, not through a branch, results in a detached HEAD state
git stash = create a stash point
git stash list = list stash points
git stash list -p = list stash points and show diffs per stash
git stash apply = apply most recent stash
git stash pop = apply most recent stash, and remove it from saved stashes
git stash apply (stash reference) = apply a specific stash point
git stash save "(description)" = create a stash point, be more descriptive

## reference:
- https://www.youtube.com/watch?v=FyAAIHHClqI
