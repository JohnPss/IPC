public class Caminhao extends Veiculo {
    private double capacidadeCarga;

    public Caminhao(String placa, String modelo, double capacidadeCarga) {
        super(placa, modelo);
        this.capacidadeCarga = capacidadeCarga;
    }

    @Override
    public double calcularCusto(double distancia) {
        return 1 * distancia;
    }

    @Override
    public String getDetalhes() {
        return super.getDetalhes() + ", Capacidade de Carga: " + capacidadeCarga;
    }

    public double getCapacidadeCarga() {
        return capacidadeCarga;
    }
}
