package exceptions;

public class EmptyOrderException extends Exception {
    public EmptyOrderException(String message) {
        super(message);
    }
}
