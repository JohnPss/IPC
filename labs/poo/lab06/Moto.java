public class Moto extends Veiculo {
    private int cilindradas;

    public Moto(String placa, String modelo, int cilindradas) {
        super(placa, modelo);
        this.cilindradas = cilindradas;
    }

    @Override
    public double calcularCusto(double distancia) {
        return 0.2 * distancia;
    }

    @Override
    public String getDetalhes() {
        return super.getDetalhes() + ", Cilindradas: " + cilindradas;
    }

    public int getCilindradas() {
        return cilindradas;
    }

}
