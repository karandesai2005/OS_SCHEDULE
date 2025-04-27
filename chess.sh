#!/bin/bash

# Define chess pieces (Unicode or simple text for clarity)
# White pieces
WK="♔" # King
WQ="♕" # Queen
WR="♖" # Rook
WB="♗" # Bishop
WN="♘" # Knight
WP="♙" # Pawn
# Black pieces
BK="♚" # King
BQ="♛" # Queen
BR="♜" # Rook
BB="♝" # Bishop
BN="♞" # Knight
BP="♟" # Pawn
# Empty square
EM=" "

# Function to print the chessboard
print_board() {
    echo "   a b c d e f g h"
    echo "  ----------------"
    for ((row=8; row>=1; row--)); do
        echo -n "$row |"
        for ((col=1; col<=8; col++)); do
            # Place pieces based on starting position
            if [ $row -eq 8 ]; then
                case $col in
                    1|8) piece=$BR ;;
                    2|7) piece=$BN ;;
                    3|6) piece=$BB ;;
                    4) piece=$BQ ;;
                    5) piece=$BK ;;
                esac
            elif [ $row -eq 7 ]; then
                piece=$BP
            elif [ $row -eq 2 ]; then
                piece=$WP
            elif [ $row -eq 1 ]; then
                case $col in
                    1|8) piece=$WR ;;
                    2|7) piece=$WN ;;
                    3|6) piece=$WB ;;
                    4) piece=$WQ ;;
                    5) piece=$WK ;;
                esac
            else
                piece=$EM
            fi
            echo -n "$piece|"
        done
        echo " $row"
        echo "  ----------------"
    done
    echo "   a b c d e f g h"
}

# Display the board
echo "Chessboard:"
print_board
