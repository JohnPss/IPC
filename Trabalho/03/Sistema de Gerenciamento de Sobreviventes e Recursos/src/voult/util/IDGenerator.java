package voult.util;

import java.util.UUID;

public class IDGenerator {
    public static String nextUUID() {
        return UUID.randomUUID().toString();
    }
}
