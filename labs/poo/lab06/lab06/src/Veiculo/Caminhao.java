package Veiculo;

public class Caminhao extends Veiculo {
    private static final double CUSTO_POR_KM = 1.00;
    private double capacidadeMaxima;

    public Caminhao(String placa, String modelo, int capacidade, double capacidadeMaxima) {
        super(placa, modelo, capacidade);
        this.capacidadeMaxima = capacidadeMaxima;
    }

    public double getCapacidadeMaxima() {
        return capacidadeMaxima;
    }

    public void setCapacidadeMaxima(double capacidadeMaxima) {
        this.capacidadeMaxima = capacidadeMaxima;
    }

    @Override
    public double calcularCusto(double distancia) {
        return distancia * CUSTO_POR_KM;
    }

    @Override
    public String getDetalhes() {
        return "Tipo: Caminhão\n" +
                super.getDetalhes() +
                "\nCapacidade Máxima: " + capacidadeMaxima + " toneladas";
    }
}