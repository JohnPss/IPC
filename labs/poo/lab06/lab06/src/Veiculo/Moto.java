package Veiculo;

public class Moto extends Veiculo {
    private static final double CUSTO_POR_KM = 0.20;
    private int cilindrada;

    public Moto(String placa, String modelo, int capacidade, int cilindrada) {
        super(placa, modelo, capacidade);
        this.cilindrada = cilindrada;
    }

    public int getCilindrada() {
        return cilindrada;
    }

    public void setCilindrada(int cilindrada) {
        this.cilindrada = cilindrada;
    }

    @Override
    public double calcularCusto(double distancia) {
        return distancia * CUSTO_POR_KM;
    }

    @Override
    public String getDetalhes() {
        return "Tipo: Moto\n" +
                super.getDetalhes() +
                "\nCilindrada: " + cilindrada + "cc";
    }
}