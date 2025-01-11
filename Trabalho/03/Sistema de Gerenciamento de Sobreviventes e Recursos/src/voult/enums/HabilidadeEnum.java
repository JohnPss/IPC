package voult.enums;

public enum HabilidadeEnum {
    ENGENHARIA(1),
    MEDICINA(2),
    COMBATE(3),
    EXPLORACAO(4),
    CULINARIA(5),
    DIPLOMACIA(6),
    HACKEAMENTO(7),
    FURTIVIDADE(8);

    private final int valor;

    HabilidadeEnum(int valor) {
        this.valor = valor;
    }

    public int getValor() {
        return valor;
    }

    public static HabilidadeEnum fromkey(int valor) {
        for (HabilidadeEnum habilidade : HabilidadeEnum.values()) {
            if (habilidade.getValor() == valor) {
                return habilidade;
            }
        }
        throw new IllegalArgumentException("Chave inválida: " + valor);
    }

    public static void exibirHabilidades() {
        for (HabilidadeEnum habilidade : HabilidadeEnum.values()) {
            System.out.println(habilidade.getValor() + ": " + habilidade);
        }
    }
}
