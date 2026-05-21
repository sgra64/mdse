# define useful aliases
alias l="ls -la"
alias mk="make"

# Build an run the program. Flag '-b' forces rebuild and '-c'
# clears the terminal output before running.
# - usage: run [-c,-b]
function run() {
    local cmd="make && out/main"
    case "$1" in
    "-c")           clear ;;
    "-b")           make clean ;;
    "-cb"|"-bc")    make clean && clean ;;
    "--help"|"-h")  echo "usage: run [-c,-b]" ;;
    esac
    echo "--> $cmd" && eval $cmd
}
