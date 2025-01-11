package voult.enums;

public enum TipoRecursoEnum {
    AGUA(1), COMIDA(2), REMEDIO(3), MUNICAO(4), PARTESMECANICAS(5);

    private final int valor;

    TipoRecursoEnum(int valor) {
        this.valor = valor;
    }

    public int getValor() {
        return valor;
    }

    public static TipoRecursoEnum fromkey(int valor) {
        for (TipoRecursoEnum recurso : TipoRecursoEnum.values()) {
            if (recurso.getValor() == valor) {
                return recurso;
            }
        }
        throw new IllegalArgumentException("Chave inválida: " + valor);
    }

    public static void exibirRecursos() {
        for (TipoRecursoEnum recurso : TipoRecursoEnum.values()) {
            System.out.println(recurso.getValor() + ": " + recurso);
        }
    }

}
