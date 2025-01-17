import voult.core.voult;
import voult.model.*;
import voult.enums.*;
import java.util.ArrayList;

public class TestDataPopulator {
    public static void popularDados(voult vault) {
        // Adicionar sobreviventes
        Sobrevivente s1 = new Sobrevivente("João Pedro", 25, StatusSobreviventeEnum.ATIVO);
        s1.addHabilidade(HabilidadeEnum.COMBATE);
        s1.addHabilidade(HabilidadeEnum.DIPLOMACIA);
        s1.addHabilidade(HabilidadeEnum.HACKEAMENTO);
        vault.addSobrevivente(s1);

        Sobrevivente s2 = new Sobrevivente("Habib", 30, StatusSobreviventeEnum.ATIVO);
        s2.addHabilidade(HabilidadeEnum.ENGENHARIA);
        s2.addHabilidade(HabilidadeEnum.MEDICINA);
        s2.addHabilidade(HabilidadeEnum.DIPLOMACIA);
        vault.addSobrevivente(s2);

        Sobrevivente s3 = new Sobrevivente("Pedro", 28, StatusSobreviventeEnum.FERIDO);
        s3.addHabilidade(HabilidadeEnum.FURTIVIDADE);
        s3.addHabilidade(HabilidadeEnum.COMBATE);
        vault.addSobrevivente(s3);

        Sobrevivente s4 = new Sobrevivente("Aragorn", 22, StatusSobreviventeEnum.ATIVO);
        s4.addHabilidade(HabilidadeEnum.MEDICINA);
        s4.addHabilidade(HabilidadeEnum.COMBATE);
        vault.addSobrevivente(s4);

        Sobrevivente s5 = new Sobrevivente("Matheus", 22, StatusSobreviventeEnum.ATIVO);
        s5.addHabilidade(HabilidadeEnum.FURTIVIDADE);
        vault.addSobrevivente(s5);

        Sobrevivente s6 = new Sobrevivente("Bernardo", 22, StatusSobreviventeEnum.ATIVO);
        s6.addHabilidade(HabilidadeEnum.COMBATE);
        s6.addHabilidade(HabilidadeEnum.EXPLORACAO);
        vault.addSobrevivente(s6);

        Sobrevivente s7 = new Sobrevivente("Ahmed", 22, StatusSobreviventeEnum.ATIVO);
        s7.addHabilidade(HabilidadeEnum.FURTIVIDADE);
        s7.addHabilidade(HabilidadeEnum.CULINARIA);
        vault.addSobrevivente(s7);

        Sobrevivente s8 = new Sobrevivente("Alvaro", 22, StatusSobreviventeEnum.MORTO);
        s8.addHabilidade(HabilidadeEnum.EXPLORACAO);
        s8.addHabilidade(HabilidadeEnum.DIPLOMACIA);
        vault.addSobrevivente(s8);

        Sobrevivente s9 = new Sobrevivente("Jubiscleiton", 22, StatusSobreviventeEnum.DOENTE);
        s9.addHabilidade(HabilidadeEnum.EXPLORACAO);
        s9.addHabilidade(HabilidadeEnum.DIPLOMACIA);
        vault.addSobrevivente(s9);

        // Adicionar recursos
        vault.addRecurso(new Recurso(TipoRecursoEnum.AGUA, 11));
        vault.addRecurso(new Recurso(TipoRecursoEnum.COMIDA, 15));
        vault.addRecurso(new Recurso(TipoRecursoEnum.REMEDIO, 5));
        vault.addRecurso(new Recurso(TipoRecursoEnum.MUNICAO, 22));
        vault.addRecurso(new Recurso(TipoRecursoEnum.PARTES_MECANICAS, 1));

        // Criar e adicionar missões
        ArrayList<Recurso> recursosMissao1 = new ArrayList<>();
        recursosMissao1.add(new Recurso(TipoRecursoEnum.AGUA, 20));
        recursosMissao1.add(new Recurso(TipoRecursoEnum.REMEDIO, 10));
        Missao missao1 = new Missao("Busca Hospital", "Procurar medicamentos", "Hospital Central", recursosMissao1,
                StatusMissaoEnum.SUCESSO);
        missao1.adicionarSobrevivente(s1.getIndentificador());
        missao1.adicionarSobrevivente(s2.getIndentificador());
        vault.addMissao(missao1);

        ArrayList<Recurso> recursosMissao2 = new ArrayList<>();
        recursosMissao2.add(new Recurso(TipoRecursoEnum.COMIDA, 30));
        recursosMissao2.add(new Recurso(TipoRecursoEnum.MUNICAO, 15));
        Missao missao2 = new Missao("Explorar Mercado", "Buscar suprimentos", "Mercado Abandonado", recursosMissao2,
                StatusMissaoEnum.EM_ANDAMENTO);
        missao2.adicionarSobrevivente(s3.getIndentificador());
        missao2.adicionarSobrevivente(s4.getIndentificador());
        vault.addMissao(missao2);
    }
}
