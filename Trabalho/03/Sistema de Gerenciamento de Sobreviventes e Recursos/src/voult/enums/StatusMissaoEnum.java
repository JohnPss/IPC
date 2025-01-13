package voult.enums;

public enum StatusMissaoEnum {
    EM_ANDAMENTO(1), SUCESSO(2), FRACASSO(3);

    private final int valor;

    StatusMissaoEnum(int valor) {
        this.valor = valor;
    }

    public int getValor() {
        return valor;
    }

    public static StatusMissaoEnum fromkey(int valor) {
        for (StatusMissaoEnum status : StatusMissaoEnum.values()) {
            if (status.getValor() == valor) {
                return status;
            }
        }
        throw new IllegalArgumentException("Chave inválida: " + valor);
    }

    public static void exibirStatus() {
        for (StatusMissaoEnum status : StatusMissaoEnum.values()) {
            System.out.println(status.getValor() + ": " + status);
        }
    }

}
