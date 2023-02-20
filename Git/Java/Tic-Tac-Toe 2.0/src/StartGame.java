import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class StartGame {
    public static class Players {
        private final int id;
        private final char name;
        private boolean chance = false;

        public Players(int id, char name) {
            this.id = id;
            this.name = name;
        }

        public void setChance(boolean chance) {
            this.chance = chance;
        }

        public int getId() {
            return id;
        }

        public char getName() {
            return name;
        }

        public boolean isChance() {
            return chance;
        }
    }

    public static class Board {
        private static final int ZERO = 0;
        private static final int ONE = 1;

        private final int boardSize;
        private final char[][] board;

        public Board(int playerNum) {
            this.boardSize = playerNum + ONE;

            this.board = new char[playerNum + ONE][playerNum + ONE];

            //inintialise board with '-'
            //'- will be taken as empty position'
            for (int i = ZERO; i < boardSize; i++) {
                for (int j = ZERO; j < boardSize; j++) {
                    this.board[i][j] = '-';
                }
            }

        }

        public void printBoard() {
            System.out.println();
            printBorder();
            for (int i = ZERO; i < boardSize; i++) {
                for (int j = ZERO; j < boardSize; j++) {
                    StringBuffer stringBuffer = new StringBuffer();
                    if (j == 0) {
                        stringBuffer.append("#  ");
                    }
                    stringBuffer.append(board[i][j]).append("  ");
                    System.out.print(stringBuffer);
                }
                System.out.println("#");
            }
            printBorder();
        }

        private void printBorder() {
            StringBuffer border = new StringBuffer();
            int borderLength = boardSize + 2;
            for (int i = 0; i < borderLength; i++) {
                border.append("#  ");
            }
            System.out.println(border);
        }

        public int insert(int[] position, char c) {
            int row = position[ZERO];
            int col = position[ONE];

            //if position is occupied return -ONE
            //unble to insert at this position
            if (board[row][col] != '-')
                return -ONE;

            board[row][col] = c;
            return ZERO;
        }

        //to check game tie
        public boolean boardISFull() {
            for (int i = ZERO; i < boardSize; i++) {
                for (int j = ZERO; j < boardSize; j++) {
                    //if none position is left empty
                    if (board[i][j] == '-')
                        return false;
                }
            }
            System.out.println("NO ONE WIN");
            return true;
        }

        //to check if somebody won, will return his character
        //victory is the int needed to win in  a row
        public List<String> playerWon(int victory) {
            List<String> result = new ArrayList<>();
            StringBuilder diagonal1 = new StringBuilder();
            StringBuilder diagonal2 = new StringBuilder();
            for (int i = ZERO; i < victory + ONE; i++) {
                StringBuilder rowValue = new StringBuilder();
                StringBuilder columnValue = new StringBuilder();
                for (int j = ZERO; j < victory + ONE; j++) {
                    rowValue.append(board[i][j]);
                    columnValue.append(board[j][i]);
                }
                result.add(rowValue.toString());
                result.add(columnValue.toString());
                diagonal1.append(board[i][i]);
                diagonal2.append(board[victory - i][i]);
            }
            result.add(diagonal1.toString());
            result.add(diagonal2.toString());

            if (victory < boardSize) {
                StringBuilder diagonal3 = new StringBuilder();
                StringBuilder diagonal4 = new StringBuilder();
                StringBuilder diagonal5 = new StringBuilder();
                StringBuilder diagonal6 = new StringBuilder();
                for (int i = boardSize - victory; i < boardSize; i++) {
                    for (int j = boardSize - i; j > victory - i; j--) {
                        diagonal6.append(board[j - ONE][i - ONE]);
                        diagonal5.append(board[j][i]);
                        diagonal3.append(board[i][i - ONE]);
                        diagonal4.append(board[i - ONE][i]);
                    }
                }
                result.add(diagonal3.toString());
                result.add(diagonal4.toString());
                result.add(diagonal5.toString());
                result.add(diagonal6.toString());
            }
            return result;
        }
    }

    public static class PlayGameService {
        private static final int NEGATIVE_ONE = -1;
        private static final int ZERO = 0;
        private static final int ONE = 1;

        private final ArrayList<Players> players = new ArrayList<>();
        private final int playerNum;
        private final Scanner scanner;
        private final Board board;

        private int victoryNumber = ZERO;

        public PlayGameService(int involvedNum, Scanner scanner) {
            this.playerNum = involvedNum;
            this.scanner = scanner;
            this.board = new Board(involvedNum);
        }

        public void execute() {
            buildPlayers();
            playGame();
        }

        private void playGame() {
            this.players.get(ZERO).setChance(true);

            System.out.println("ENTER POSITION ON BOARD FOR PLAYERS");

            do {
                this.board.printBoard();

                //for every player in list get their position input, insert into board
                //and check if they won
                for (Players player : this.players) {
                    if (!player.isChance())
                        continue;

                    //id starts from 1
                    int playerIndex = player.getId() - ONE;
                    System.out.print("(WARNING: INPUT TYPE MUST BE INT)\n");
                    System.out.print("PLEASE INPUT X AND Y POSITION \n");
                    System.out.print("PLAYER " + player.getId() + " (" + player.getName() + ") : ");

                    //while we don't get right position to insert into board
                    while (true) {
                        int row = this.scanner.nextInt();
                        int column = this.scanner.nextInt();

                        this.scanner.nextLine();
                        //index so -1
                        int[] position = {row - ONE, column - ONE};
                        if (isLegalCheckerboard(player, row, column, position)) break;
                    }
                    //make this players chance as false and next players as true
                    this.players.get(playerIndex).setChance(false);
                    playerIndex++;

                    //if we reach end of list make first player chance true
                    restartPlayStatus(playerIndex);
                    break;
                }
                //update status
            } while (!isGameEnded());

            this.board.printBoard();
        }

        // check checkerboard
        private boolean isLegalCheckerboard(Players player, int row, int column, int[] position) {
            if (isUnLegalPositionValue(row, column)) {
                System.out.print("THIS POSITION DOES NOT EXIST ON BOARD: ");
            } else if (this.board.insert(position, player.getName()) == NEGATIVE_ONE) {
                System.out.print("THIS POSITION IS ALREADY OCCUPIED ON BOARD: ");
            } else {
                return true;
            }
            return false;
        }

        private boolean isGameEnded() {
            //game end if its a tie, or a player has won
            List<String> result = this.board.playerWon(victoryNumber);
            if (!result.isEmpty()) {
                for (Players player : players) {
                    StringBuilder stringBuilder = new StringBuilder();
                    for (int i = ZERO; i < victoryNumber; i++) {
                        stringBuilder.append(player.getName());
                    }
                    if (isMatchSucceed(result, stringBuilder)) {
                        System.out.println("\nPLAYER " + player.getId() + " HAS WON !!!");
                        return true;
                    }
                }
                return this.board.boardISFull();
            }
            return false;
        }

        private boolean isMatchSucceed(List<String> result, StringBuilder stringBuilder) {
            for (String string: result) {
                if (string.contains(stringBuilder.toString())) {
                    return true;
                }
            }
            return false;
        }

        private void restartPlayStatus(int playerIndex) {
            if (playerIndex == playerNum)
                this.players.get(ZERO).setChance(true);
            else
                this.players.get(playerIndex).setChance(true);
        }

        private boolean isUnLegalPositionValue(int row, int column) {
            return row < ZERO || column < ZERO || row > playerNum + ONE || column > playerNum + ONE;
        }

        private void buildPlayers() {
            System.out.println("\nPLEASE SET NAME FOR ALL PLAYERS");
            List<Character> nameHub = new ArrayList<>();

            for (int i = ZERO; i < playerNum; i++) {
                int playerId = i + ONE;
                char playerName;

                do {
                    System.out.print("(WARNING: PLAYER NAME SHOULD NOT )\n");
                    System.out.print("PLAYER " + (playerId) + " NAME IS : ");
                    playerName = this.scanner.nextLine().charAt(ZERO);
                } while (nameHub.contains(playerName));

                this.players.add(new Players(playerId, playerName));
                nameHub.add(playerName);
            }

            do {
                System.out.print("How many repeats in a row to win: ");
                this.victoryNumber = this.scanner.nextInt();
                this.scanner.nextLine();
            } while (!isLegalVictoryNumber(victoryNumber));
        }

        private boolean isLegalVictoryNumber(int victoryNumber) {
            return victoryNumber <= this.playerNum;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("The Game is start");
        while (true) {
            System.out.print("(WARING: INPUT TYPE MUST BE INT !!!)\n");
            System.out.print("PLEASE INPUT THE NUMBER OF PLAYERS: ");
            String inputNumber = scanner.nextLine();

            if (!isNumber(inputNumber)) {
                System.out.print("INPUT VALUE IS WRONG PLEASE INPUT AGAIN !!!\n");
            } else if (!isLegalNumber(inputNumber)) {
                System.out.print("PLAYER NUMBER MUST MORE THAN TWO !!!");
            } else {
                int players = Integer.parseInt(inputNumber);
                new PlayGameService(players, scanner).execute();
                break;
            }
        }

        scanner.close();
    }

    private static boolean isLegalNumber(String inputNumber) {
        return Integer.parseInt(inputNumber) > 2;
    }

    private static boolean isNumber(String input) {
        for (int i = 0; i < input.length(); i++) {
            if (!Character.isDigit(input.charAt(i))) {
                return false;
            }
        }
        return true;
    }
}
