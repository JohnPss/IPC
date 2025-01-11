package voult.enums;

public enum StatusSobreviventeEnum {
    ATIVO(1),
    DOENTE(2),
    FERIDO(3),
    MORTO(4);

    private final int valor;

    StatusSobreviventeEnum(int valor) {
        this.valor = valor;
    }

    public int getValor() {
        return valor;
    }

    public static StatusSobreviventeEnum fromkey(int valor) {
        for (StatusSobreviventeEnum status : StatusSobreviventeEnum.values()) {
            if (status.getValor() == valor) {
                return status;
            }
        }
        throw new IllegalArgumentException("Chave inválida: " + valor);
    }

    public static void exibirStatus() {
        for (StatusSobreviventeEnum status : StatusSobreviventeEnum.values()) {
            System.out.println(status.getValor() + ": " + status);
        }
    }

}
